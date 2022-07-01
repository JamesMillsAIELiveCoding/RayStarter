#include "Config.h"

#include <fstream>
#include <sstream>
#include <raymath.h>

using std::ifstream;
using std::ios;

Config* Config::m_instance = nullptr;

Config::Config(string _filePath)
{
	m_filePath = _filePath;
	Load(m_filePath);
}

void Config::Reload()
{
	m_instance->m_configData.clear();
	m_instance->Load(m_instance->m_filePath);
}

int Config::GetIntValue(string _group, string _id)
{
	if (m_instance->m_configData.find(_group) != m_instance->m_configData.end())
	{
		ConfigSet& set = m_instance->m_configData[_group];

		if (set.find(_id) != set.end())
		{
			return atoi(set[_id].c_str());
		}
	}

	return 0;
}

bool Config::GetBooleanValue(string _group, string _id)
{
	if (m_instance->m_configData.find(_group) != m_instance->m_configData.end())
	{
		ConfigSet& set = m_instance->m_configData[_group];

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
	if (m_instance->m_configData.find(_group) != m_instance->m_configData.end())
	{
		ConfigSet& set = m_instance->m_configData[_group];

		if (set.find(_id) != set.end())
		{
			return (float)atof(set[_id].c_str());
		}
	}

	return 0;
}

Vector2 Config::GetVectorValue(string _group, string _id)
{
	if (m_instance->m_configData.find(_group) != m_instance->m_configData.end())
	{
		ConfigSet& set = m_instance->m_configData[_group];

		if (set.find(_id) != set.end())
		{
			string token;
			string delim = ",";
			string s = set[_id];

			float values[2];
			size_t pos = 0;
			int index = 0;
			while ((pos = s.find(delim)) != string::npos)
			{
				token = s.substr(0, pos);
				values[index++] = std::stof(token);
				s.erase(0, pos + delim.length());
			}

			values[index++] = std::stof(s);

			return Vector2{ values[0], values[1] };
		}
	}

	return Vector2();
}

Color Config::GetColorValue(string _group, string _id)
{
	if (m_instance->m_configData.find(_group) != m_instance->m_configData.end())
	{
		ConfigSet& set = m_instance->m_configData[_group];

		if (set.find(_id) != set.end())
		{
			string token;
			string delim = ",";
			string s = set[_id];

			unsigned char values[4];
			size_t pos = 0;
			int index = 0;
			while ((pos = s.find(delim)) != string::npos)
			{
				token = s.substr(0, pos);
				values[index++] = std::stoi(token);
				s.erase(0, pos + delim.length());
			}

			values[index++] = std::stoi(s);

			return Color{ values[0], values[1], values[2], values[3] };
		}
	}

	return Color();
}

const char* Config::GetTextValue(string _group, string _id)
{
	if (m_instance->m_configData.find(_group) != m_instance->m_configData.end())
	{
		ConfigSet& set = m_instance->m_configData[_group];

		if (set.find(_id) != set.end())
		{
			return set[_id].c_str();
		}
	}

	return 0;
}

void Config::Load(string _filePath)
{
	ifstream configFile("assets\\" + _filePath);
	if (configFile.bad())
		throw "Config file missing";

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

	configFile.close();
}