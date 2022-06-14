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
	Assets();
	~Assets();
	Texture2D GetTexture(const char* _id);
	Sound GetSound(const char* _id);
	Font GetFont(const char* _id);

private:
	void Load();
	void Unload();
	void LoadTextures();
	void LoadSounds();
	void LoadFonts();

	std::map<string, Texture2D> textures;
	std::map<string, Sound> sounds;
	std::map<string, Font> fonts;

};

extern Assets* assets;