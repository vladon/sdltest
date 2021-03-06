#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
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

	TTF_Font* Font;

	SDL_Surface* Line;
};

