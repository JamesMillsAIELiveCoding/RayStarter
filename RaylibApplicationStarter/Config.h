#pragma once

#define PROGRAM_CATEGORY "Program"
#define DEBUG_CATEGORY "Debug"

#include <string>
#include <map>

using std::string;
using std::map;

typedef string GroupID;
typedef map<string, string> ConfigSet;

struct InvalidValueException : public std::exception
{
	string value;

	InvalidValueException(string _value) : value("Key not found: " + _value) {}

	const char* what() const throw ()
	{
		return value.c_str();
	}
};

struct Config
{
	Config(string _filePath) : m_filePath(_filePath) { Load(); }

	int GetIntValue(string _group, string _id);
	bool GetBooleanValue(string _group, string _id);
	float GetFloatValue(string _group, string _id);
	const char* GetTextValue(string _group, string _id);

private:
	void Load();
	string m_filePath;
	map<GroupID, ConfigSet> m_configData;
};

extern Config config;