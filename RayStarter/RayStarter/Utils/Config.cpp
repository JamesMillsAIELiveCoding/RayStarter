#include "Config.h"

#include <fstream>
#include <sstream>
#include <vector>

using std::ifstream;
using std::ios;
using std::vector;

Config* Config::m_instance = nullptr;

Config::Config(string _filePath)
{
	m_filePath = _filePath;
	Load(m_filePath);
}

void Config::Reload()
{
	m_instance->m_intValues.clear();
	m_instance->m_boolValues.clear();
	m_instance->m_floatValues.clear();
	m_instance->m_vectorValues.clear();
	m_instance->m_colorValues.clear();
	m_instance->m_textValues.clear();

	m_instance->Load(m_instance->m_filePath);
}

int Config::GetIntValue(string _group, string _id)
{
	if (m_instance->m_intValues.find(_group) != m_instance->m_intValues.end())
	{
		auto& set = m_instance->m_intValues[_group];

		if (set.find(_id) != set.end())
		{
			return set[_id];
		}
	}

	return 0;
}

bool Config::GetBooleanValue(string _group, string _id)
{
	if (m_instance->m_boolValues.find(_group) != m_instance->m_boolValues.end())
	{
		auto& set = m_instance->m_boolValues[_group];

		if (set.find(_id) != set.end())
		{
			return set[_id];
		}
	}

	return false;
}

float Config::GetFloatValue(string _group, string _id)
{
	if (m_instance->m_floatValues.find(_group) != m_instance->m_floatValues.end())
	{
		auto& set = m_instance->m_floatValues[_group];

		if (set.find(_id) != set.end())
		{
			return set[_id];
		}
	}

	return 0;
}

Vector2 Config::GetVectorValue(string _group, string _id)
{
	if (m_instance->m_vectorValues.find(_group) != m_instance->m_vectorValues.end())
	{
		auto& set = m_instance->m_vectorValues[_group];

		if (set.find(_id) != set.end())
		{
			return set[_id];
		}
	}

	return Vector2{};
}

Color Config::GetColorValue(string _group, string _id)
{
	if (m_instance->m_colorValues.find(_group) != m_instance->m_colorValues.end())
	{
		auto& set = m_instance->m_colorValues[_group];

		if (set.find(_id) != set.end())
		{
			return set[_id];
		}
	}

	return Color();
}

const char* Config::GetTextValue(string _group, string _id)
{
	if (m_instance->m_textValues.find(_group) != m_instance->m_textValues.end())
	{
		auto& set = m_instance->m_textValues[_group];

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

			if (val.find(',') != -1)
			{
				// color / vector
				string token;
				string delim = ",";
				string s = val;

				vector<float> values;
				size_t pos = 0;
				while ((pos = s.find(delim)) != string::npos)
				{
					token = s.substr(0, pos);
					values.push_back(std::stof(token));
					s.erase(0, pos + delim.length());
				}

				values.push_back(std::stof(s));

				if (values.size() == 2)
				{
					m_vectorValues[lastGroup][id] = Vector2{ values[0], values[1] };
				}
				else if (values.size() == 4)
				{
					m_colorValues[lastGroup][id] = Color
					{
						(unsigned char)values[0],
						(unsigned char)values[1],
						(unsigned char)values[2],
						(unsigned char)values[3]
					};
				}
			}
			else
			{
				if (val.find('.') != -1)
				{
					m_floatValues[lastGroup][id] = (float)atof(val.c_str());
					continue;
				}

				if (val == "false" || val == "true")
				{
					m_boolValues[lastGroup][id] = val == "true";
				}
				else
				{
					int ascii = (int)val[0];
					if (ascii >= 48 && ascii <= 57)
					{
						m_intValues[lastGroup][id] = atoi(val.c_str());
					}
					else
					{
						m_textValues[lastGroup][id] = val;
					}
				}
			}
		}
	}

	configFile.close();
}