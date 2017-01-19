//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Gelo123321 - 2017. +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "StateParser.h"
#include "TextureManager.h"
#include "Game.h"
#include "GameObjectFactory.h"

using namespace std;
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

bool StateParser::parseState(const char *stateFile, string stateID, vector<GameObject *> *pObjects, std::vector<std::string> *pTextureIDs)
{
	// create the XML document
	TiXmlDocument xmlDoc;

	// load the state file
	if (!xmlDoc.LoadFile(stateFile))
	{
		cerr << xmlDoc.ErrorDesc() << "\n";
		return false;
	}

	// get the root element
	TiXmlElement* pRoot = xmlDoc.RootElement();

	// pre declare the states root node
	TiXmlElement* pStateRoot = 0;
	// get this states root node and assing it to pStateRoot
	for (TiXmlElement* e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if (e->Value() == stateID)
		{
			pStateRoot = e;
			break;
		}
	}

	// pre declare the texture root
	TiXmlElement* pTextureRoot = 0;

	// get the root of the texture elements
	for (TiXmlElement* e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if (e->Value() == string("TEXTURES"))
		{
			pTextureRoot = e;
			break;
		}
	}

	// now parse the textures
	parseTextures(pTextureRoot, pTextureIDs);

	// pre declare the object root node
	TiXmlElement* pObjectRoot = 0;

	// get the root node and assign it to pObjectRoot
	for (TiXmlElement* e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if (e->Value() == string("OBJECTS"))
		{
			pObjectRoot = e;
			break;
		}
	}

	// now parse the objects
	parseObjects(pObjectRoot, pObjects, pRoot);

	return true;
}

bool StateParser::setAttribute(const char* stateFile, std::string stateID, std::string level)
{
	// create the XML document
	TiXmlDocument xmlDoc;

	// load the state file
	if (!xmlDoc.LoadFile(stateFile))
	{
		cerr << xmlDoc.ErrorDesc() << "\n";
		return false;
	}

	// get the root element
	TiXmlElement* pRoot = xmlDoc.RootElement();

	// pre declare the states root node
	TiXmlElement* pStateRoot = 0;
	// get this states root node and assing it to pStateRoot
	for (TiXmlElement* e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if (e->Value() == stateID)
		{
			pStateRoot = e;
			break;
		}
	}


	// pre declare the object root node
	TiXmlElement* pObjectRoot = 0;

	// get the root node and assign it to pObjectRoot
	for (TiXmlElement* e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if (e->Value() == string("OBJECTS"))
		{
			pObjectRoot = e;
			break;
		}
	}

	string currentLevel = "";
	for (int i = 0; i < level.length(); i++)
	{
		if (isdigit(level[i]))
		{
			currentLevel += level[i];
		}
	}

	currentLevel = to_string(stoi(currentLevel) + 1);

	for (TiXmlElement* e = pObjectRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if (strcmp(e->Attribute("type"), "MenuButton") == 0 &&
			strcmp(e->Attribute("callbackID"), currentLevel.c_str()) == 0)
		{
			e->SetAttribute("textureID", "lvl_open");
			continue;
		}
	}

	xmlDoc.SaveFile();

	return true;
}

void StateParser::parseTextures(TiXmlElement* pStateRoot, std::vector<std::string> *pTextureIDs)
{
	// for each texture we get the filename and the desired ID and add them to the texture manager
	for (TiXmlElement* e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		string filenameAttribute = e->Attribute("filename");
		string idAttribute = e->Attribute("ID");

		pTextureIDs->push_back(idAttribute); // push the id into the list

		TheTextureManager::Instance()->load(filenameAttribute, idAttribute, TheGame::Instance()->getRenderer().get());
	}
}

void StateParser::parseObjects(TiXmlElement *pStateRoot, std::vector<GameObject *> *pObjects, TiXmlElement* pRoot)
{
	for (TiXmlElement* e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		int x, y, width, height, numFrames, callbackID, animSpeed;
		string textureID, letter, word = "";

		e->Attribute("x", &x);
		e->Attribute("y", &y);
		e->Attribute("width", &width);
		e->Attribute("height", &height);
		e->Attribute("numFrames", &numFrames);
		e->Attribute("callbackID", &callbackID);
		e->Attribute("animSpeed", &animSpeed);

		textureID = e->Attribute("textureID");

		if (strcmp(e->Attribute("type"), "LetterButton") == 0)
		{
			letter = e->Attribute("letter");
		}
		else if (strcmp(e->Attribute("type"), "Word") == 0)
		{
			word = e->Attribute("word");
		}
		
		//int x, int y, int width, int height, std::string textureID, int numFrames, void()
		GameObject* pGameObject = TheGameObjectFactory::Instance()->create(e->Attribute("type"));
		pGameObject->load(new LoaderParams(x, y, width, height, textureID, numFrames, callbackID, animSpeed, letter, word));
		
		pObjects->push_back(pGameObject);
	}
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++