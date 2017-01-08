//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Gelo123321 - 2017. +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef PROGRESSPARSER_H
#define PROGRESSPARSER_H

#include <iostream>
#include <map>
#include "tinyxml.h"
#include "Player.h"

class ProgressParser
{
public:

	ProgressParser() {}
	~ProgressParser() {}

	bool parseProgress(const char*);
	bool saveProgress(const char*);

private:

	void parseCurrentProgress(TiXmlElement* pProgressRoot);

};

#endif
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++