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

class Config
{
public:
	static int GetIntValue(string _group, string _id);
	static bool GetBooleanValue(string _group, string _id);
	static float GetFloatValue(string _group, string _id);
	static const char* GetTextValue(string _group, string _id);
	static void CreateInstance(string _filePath) { m_instance = new Config(_filePath); }
	static void DestroyInstance() { delete m_instance; }

private:
	Config() {};
	Config(string _filePath) { Load(_filePath); }
	Config(const Config&) = delete;

	static void Load(string _filePath);
	static map<GroupID, ConfigSet> m_configData;
	static Config* m_instance;
};