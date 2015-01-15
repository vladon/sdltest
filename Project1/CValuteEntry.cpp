#include "CValuteEntry.h"
#include <SDL.h>
#include <SDL_image.h>

CValuteEntry::CValuteEntry(std::string ANominal, std::string ACharCode, std::string AValue)
{
	flag_texture = nullptr;

	Nominal = ANominal;
	CharCode = ACharCode;
	Value = AValue;
}


CValuteEntry::~CValuteEntry()
{
	if (flag_texture) {
		SDL_DestroyTexture(flag_texture);
	}
}
