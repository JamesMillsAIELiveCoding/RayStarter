#include "Assets.h"

#include <raylib.h>

#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

std::map<string, Texture2D> Assets::textures;
std::map<string, Sound> Assets::sounds;
std::map<string, Font> Assets::fonts;

void Assets::Load()
{
	LoadTextures();
	LoadSounds();
	LoadFonts();
}

void Assets::Unload()
{
	for (auto iter : textures)
	{
		UnloadTexture(iter.second);
	}

	for (auto iter : sounds)
	{
		UnloadSound(iter.second);
	}

	for (auto iter : fonts)
	{
		UnloadFont(iter.second);
	}

	textures.clear();
	sounds.clear();
	fonts.clear();
}

void Assets::LoadTextures()
{
	string path = "\\assets\\textures";
	fs::path current = fs::current_path();
	current.concat(path.begin(), path.end());
	for (const auto& entry : fs::directory_iterator(current.c_str()))
	{
		string filePath = entry.path().u8string();
		string fileName = filePath;

		size_t index = fileName.find_last_of('\\') + 1;
		fileName = fileName.erase(0, index);
		index = fileName.find_last_of('.');
		fileName = fileName.erase(index, fileName.size() - index);

		textures[fileName] = LoadTexture(filePath.c_str());
	}
}

void Assets::LoadSounds()
{
	string path = "\\assets\\sounds";
	fs::path current = fs::current_path();
	current.concat(path.begin(), path.end());
	for (const auto& entry : fs::directory_iterator(current.c_str()))
	{
		string filePath = entry.path().u8string();
		string fileName = filePath;

		size_t index = fileName.find_last_of('\\') + 1;
		fileName = fileName.erase(0, index);
		index = fileName.find_last_of('.');
		fileName = fileName.erase(index, fileName.size() - index);

		sounds[fileName] = LoadSound(filePath.c_str());
	}
}

void Assets::LoadFonts()
{
	string path = "\\assets\\fonts";
	fs::path current = fs::current_path();
	current.concat(path.begin(), path.end());
	for (const auto& entry : fs::directory_iterator(current.c_str()))
	{
		string filePath = entry.path().u8string();
		string fileName = filePath;

		size_t index = fileName.find_last_of('\\') + 1;
		fileName = fileName.erase(0, index);
		index = fileName.find_last_of('.');
		fileName = fileName.erase(index, fileName.size() - index);

		fonts[fileName] = LoadFont(filePath.c_str());
	}
}

Texture2D Assets::GetTexture(const char* _id)
{
	return textures[_id];
}

Sound Assets::GetSound(const char* _id)
{
	return sounds[_id];
}

Font Assets::GetFont(const char* _id)
{
	return fonts[_id];
}