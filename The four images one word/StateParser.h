//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Gelo123321 - 2017. +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef STATEPARSER_H
#define STATEPARSER_H

#include <iostream>
#include <vector>
#include "tinyxml.h"
#include "LoaderParams.h"

class GameObject;

class StateParser
{
public:

	StateParser() {}
	~StateParser() {}

	bool parseState(const char* stateFile, std::string stateID, std::vector<GameObject*> *pObjects, std::vector<std::string> *pTextureIDs);
	bool setAttribute(const char* stateFile, std::string stateID, std::string level);
private:

	void parseObjects(TiXmlElement* pStateRoot, std::vector<GameObject*> *pObjects, TiXmlElement* pRoot);
	void parseTextures(TiXmlElement* pStateRoot, std::vector<std::string> *pTextureIDs);
};

#endif
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++