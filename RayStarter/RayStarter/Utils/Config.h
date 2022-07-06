#pragma once

#define PROGRAM_CATEGORY "Program"
#define WINDOW_CATEGORY "Window"
#define DEBUG_CATEGORY "Debug"

#include <string>
#include <map>
#include <raylib.h>

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
	static void Reload();

	static int GetIntValue(string _group, string _id);
	static bool GetBooleanValue(string _group, string _id);
	static float GetFloatValue(string _group, string _id);
	static Vector2 GetVectorValue(string _group, string _id);
	static Color GetColorValue(string _group, string _id);
	static const char* GetTextValue(string _group, string _id);

	static void CreateInstance(string _filePath) { m_instance = new Config(_filePath); }
	static void DestroyInstance() { delete m_instance; }

	static bool IsValid() { return m_instance->m_configData.size() > 0; }

private:
	Config() {};
	Config(string _filePath);
	Config(const Config&) = delete;
	void Load(string _filePath);

	string m_filePath;
	map<GroupID, ConfigSet> m_configData;
	static Config* m_instance;
};