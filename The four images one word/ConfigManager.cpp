//#############################################################################
// Config Manager.cpp - 17/01/2017 (Gelo123321) ###############################
//#############################################################################
#include "ConfigManager.h"
//#############################################################################
ConfigManager* ConfigManager::s_pInstanse = 0;

bool ConfigManager::load()
{
	m_config.clear();

	std::ifstream file(CONFIG_FILE_NAME);
	if (!file)
	{
		std::cout << "\TheConfigManager::load Couldn't open '" + CONFIG_FILE_NAME + "'!\n";
		return false;
	}

	while (!file.eof())
	{
		std::string line;
		std::getline(file, line, '\n');

		if (line.empty())
		{
			continue;
		}

		if (line[0] == COMMENT_CHAR)
		{
			continue;
		}

		std::vector<std::string> current = split(line, '=');

		m_config.insert(std::pair<std::string, int>(current.front(), stoi(current.back())));
	}

	std::cout << "TheConfigManager::load success!\n";
	return true;
}

int ConfigManager::get(const std::string key)
{
	std::map<std::string, int>::iterator it = m_config.find(key);

	if (it == m_config.end())
	{
		std::cout << "TheConfigManager::get Tried to get unexisting key '" + key + "'!\n";
		return 0;
	}

	return (*it).second;
}

bool ConfigManager::save()
{
	std::ofstream file(CONFIG_FILE_NAME);
	if (!file)
	{
		std::cout << "\TheConfigManager::save Couldn't open '" + CONFIG_FILE_NAME + "'!\n";
		return false;
	}

	for (std::map<std::string, int>::iterator it = m_config.begin(); it != m_config.end(); it++)
	{
		std::string line;
		line = it->first + "=" + std::to_string(it->second) + '\n';

		file << line;
	}

	file.close();

	std::cout << "TheConfigManager::save success!\n";
	return true;
}

void ConfigManager::set(const std::string key, int value)
{
	std::map<std::string, int>::iterator it = m_config.find(key);

	if (it == m_config.end()) 
	{
		m_config.insert(std::pair<std::string, int>(key, value));
		return;
	}

	it->second = value;
}

std::vector<std::string> ConfigManager::split(const std::string & str, const char delim)
{
	std::stringstream ss(str);
	std::string item;
	std::vector<std::string> elems;

	while (std::getline(ss, item, delim))
	{
		elems.push_back(item);
	}

	return elems;
}

//#############################################################################