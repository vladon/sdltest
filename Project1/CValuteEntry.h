#pragma once
#include <SDL.h>
#include <string>

class CValuteEntry
{
public:
	CValuteEntry(std::string ANominal, std::string ACharCode, std::string AValue);
	~CValuteEntry();

public:
	// no need to convert to numbers
	std::string Nominal;
	std::string CharCode;
	std::string Value;

	SDL_Rect flag_rect;
	SDL_Texture* flag_texture;
};

