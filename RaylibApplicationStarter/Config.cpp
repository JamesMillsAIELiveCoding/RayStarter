#include "Config.h"

#include <fstream>
#include <sstream>

Config config = Config("config.cfg");

using std::ifstream;
using std::ios;

int Config::GetIntValue(string _group, string _id)
{
	if (m_configData.find(_group) != m_configData.end())
	{
		ConfigSet& set = m_configData[_group];

		if (set.find(_id) != set.end())
		{
			return atoi(set[_id].c_str());
		}
	}

	return 0;
}

bool Config::GetBooleanValue(string _group, string _id)
{
	if (m_configData.find(_group) != m_configData.end())
	{
		ConfigSet& set = m_configData[_group];

		if (set.find(_id) != set.end())
		{
			bool val = false;
			if (set[_id] == "true")
				val = true;
			else if (set[_id] == "false")
				val = false;
			else
				throw InvalidValueException(set[_id]);

			return val;
		}
	}

	return false;
}

float Config::GetFloatValue(string _group, string _id)
{
	if (m_configData.find(_group) != m_configData.end())
	{
		ConfigSet& set = m_configData[_group];

		if (set.find(_id) != set.end())
		{
			return (float)atof(set[_id].c_str());
		}
	}

	return 0;
}

const char* Config::GetTextValue(string _group, string _id)
{
	if (m_configData.find(_group) != m_configData.end())
	{
		ConfigSet& set = m_configData[_group];

		if (set.find(_id) != set.end())
		{
			return set[_id].c_str();
		}
	}

	return 0;
}

void Config::Load()
{
	ifstream configFile("assets\\" + m_filePath);

	std::string line;
	std::string lastGroup;

	while (std::getline(configFile, line))
	{
		if (line.length() == 0 || line[0] == '#')
			continue;

		if (line[0] == '[')
		{
			std::string newLine = line;
			newLine.erase(0, 1);
			newLine.erase(newLine.end() - 1, newLine.end());
			lastGroup = newLine;
		}
		else
		{
			std::string id = line;
			size_t index = line.find_first_of('=');
			id.erase(index, id.length() - index);

			std::string val = line;
			val.erase(0, index + 1);

			m_configData[lastGroup][id] = val;
		}
	}
}