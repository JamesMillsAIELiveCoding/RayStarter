#pragma once

#include <map>
#include <string>

using std::string;
using std::map;

struct Texture2D;
struct Sound;
struct Font;

class Assets
{
public:
	static Texture2D GetTexture(const char* _id);
	static Sound GetSound(const char* _id);
	static Font GetFont(const char* _id);
	static void CreateInstance() { m_instance = new Assets(); }
	static void DestroyInstance() { delete m_instance; }

private:
	Assets();
	Assets(const Assets&) = delete;
	~Assets();

	static void Load();
	static void Unload();
	static void LoadTextures();
	static void LoadSounds();
	static void LoadFonts();

	static map<string, Texture2D> textures;
	static map<string, Sound> sounds;
	static map<string, Font> fonts;
	static Assets* m_instance;

};