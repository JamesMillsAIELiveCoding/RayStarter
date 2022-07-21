#pragma once

#define PROGRAM_CATEGORY "Program"
#define WINDOW_CATEGORY "Window"
#define DEBUG_CATEGORY "Debug"

#include <string>
#include <map>
#include <utility>

#include "Maths/Colour.h"
#include "Maths/Vec2.h"

using std::string;
using std::map;

typedef string GroupID;
typedef map<string, string> ConfigSet;

struct InvalidValueException : public std::exception
{
	string value;

	explicit InvalidValueException(const string& _value) : value("Key not found: " + _value) {}

	const char* what() const noexcept override
	{
		return value.c_str();
	}
};

class Config
{
public:
	static void Reload();

	static int GetIntValue(const string& _group, const string& _id);
	static bool GetBooleanValue(const string& _group, const string& _id);
	static float GetFloatValue(const string& _group, const string& _id);
	static Vec2 GetVectorValue(const string& _group, const string& _id);
	static Colour GetColorValue(const string& _group, const string& _id);
	static const char* GetTextValue(const string& _group, const string& _id);

	static void CreateInstance(const string& _filePath) { m_instance = new Config(_filePath); }
	static void DestroyInstance() { delete m_instance; }

	static bool IsValid() { return m_instance != nullptr; }

private:
	Config() = default;
	explicit Config(const string& _filePath);
	Config(const Config&) = delete;
	void Load(const string& _filePath);

	string m_filePath;
	map<GroupID, map<string, int>> m_intValues;
	map<GroupID, map<string, bool>> m_boolValues;
	map<GroupID, map<string, float>> m_floatValues;
	map<GroupID, map<string, Vec2>> m_vectorValues;
	map<GroupID, map<string, Colour>> m_colorValues;
	map<GroupID, map<string, string>> m_textValues;
	static Config* m_instance;
};