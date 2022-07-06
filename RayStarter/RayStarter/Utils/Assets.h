#pragma once

#include <map>
#include <string>

using std::string;
using std::map;

#include <raylib.h>

class Assets
{
public:
	static Texture2D GetTexture(const char* _id);
	static Image GetImage(const char* _id);
	static Sound GetSound(const char* _id);
	static Font GetFont(const char* _id);
	static void CreateInstance() { m_instance = new Assets(); }
	static void DestroyInstance() { delete m_instance; }

private:
	Assets();
	Assets(const Assets&) = delete;
	~Assets();

	void Load();
	void Unload();
	void LoadTextures();
	void LoadImages();
	void LoadSounds();
	void LoadFonts();

	map<string, Texture2D> textures;
	map<string, Image> images;
	map<string, Sound> sounds;
	map<string, Font> fonts;
	static Assets* m_instance;

};