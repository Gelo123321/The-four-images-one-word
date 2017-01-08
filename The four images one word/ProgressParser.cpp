//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Gelo123321 - 2017. +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "ProgressParser.h"

using namespace std;
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

bool ProgressParser::parseProgress(const char* progressFile)
{
	// create the XML document
	TiXmlDocument xmlDoc;

	// load the state file
	if (!xmlDoc.LoadFile(progressFile))
	{
		cerr << xmlDoc.ErrorDesc() << "\n";
		return false;
	}

	// get the root element
	TiXmlElement* pRoot = xmlDoc.RootElement();

	// pre declare the levels root
	TiXmlElement* pLevelsRoot = 0;

	// get the root of the texture elements
	for (TiXmlElement* e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if (e->Value() == string("LEVELS"))
		{
			pLevelsRoot = e;
			break;
		}
	}

	parseCurrentProgress(pLevelsRoot);

	return true;
}

bool ProgressParser::saveProgress(const char* progressFile)
{
	// create the XML document
	TiXmlDocument xmlDoc;

	// load the state file
	if (!xmlDoc.LoadFile(progressFile))
	{
		cerr << xmlDoc.ErrorDesc() << "\n";
	}

	// get the root element
	TiXmlElement* pRoot = xmlDoc.RootElement();

	// pre declare the levels root
	TiXmlElement* pLevelsRoot = 0;

	// get the root of the texture elements
	for (TiXmlElement* e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if (e->Value() == string("LEVELS"))
		{
			pLevelsRoot = e;
			break;
		}
	}

	// save current progress
	for (TiXmlElement* e = pLevelsRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		int lvl = ThePlayer::Instance()->getProgress("none");
		e->SetAttribute("value", lvl);

	}

	xmlDoc.SaveFile("progress.xml");

	return true;
}

void ProgressParser::parseCurrentProgress(TiXmlElement* pStateRoot)
{
	for (TiXmlElement* e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		std::string key;
		int value;

		key = e->Attribute("key");
		value = stoi(e->Attribute("value"));

		ThePlayer::Instance()->setProgress(key, value);
	}
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++