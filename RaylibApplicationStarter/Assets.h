#pragma once

#include <map>
#include <string>

using std::string;

struct Texture2D;
struct Sound;
struct Font;

struct Assets
{
public:
	static void Load();
	static void Unload();
	static Texture2D GetTexture(const char* _id);
	static Sound GetSound(const char* _id);
	static Font GetFont(const char* _id);

private:
	static void LoadTextures();
	static void LoadSounds();
	static void LoadFonts();

	static std::map<string, Texture2D> textures;
	static std::map<string, Sound> sounds;
	static std::map<string, Font> fonts;

};