//#############################################################################
// Config Manager.h - 17/01/2017 (Gelo123321) #################################
//#############################################################################
#ifndef CONFIGMANAGER_H
#define CONFIGMANAGER_H

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
//#############################################################################
class ConfigManager
{
public:
	static ConfigManager* Instance()
	{
		if (s_pInstanse == 0) 
		{
			s_pInstanse = new ConfigManager();
			return s_pInstanse;
		}
		return s_pInstanse;
	}

	bool load();
	int get(std::string key);
	bool save();
	void set(std::string key, int value);

private:

	std::vector<std::string> split(const std::string& str, char delim);

	const std::string CONFIG_FILE_NAME = "config.ini";
	const char COMMENT_CHAR = '#';

	std::map<std::string, int> m_config;
	
	ConfigManager() {}
	~ConfigManager() {}

	ConfigManager(const ConfigManager&) = delete;
	ConfigManager& operator=(const ConfigManager&) = delete;

	static ConfigManager *s_pInstanse;
};
typedef ConfigManager TheConfigManager;
#endif
//#############################################################################