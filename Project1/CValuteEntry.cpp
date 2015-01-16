#include "CValuteEntry.h"
#include "sdltest2.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

CValuteEntry::CValuteEntry(std::string ANominal, std::string ACharCode, std::string AValue)
{
	Font = TTF_OpenFont(FONT_FILENAME, FONT_SIZE);

    Nominal = ANominal;
	CharCode = ACharCode;
	Value = AValue;

	SDL_Color blackColor = { 0, 0, 0 };
	SDL_Surface* LeftText = TTF_RenderText_Blended(Font, ANominal.c_str(), blackColor);
	SDL_Surface* EqualText = TTF_RenderText_Blended(Font, " = ", blackColor);
	SDL_Surface* RightText = TTF_RenderText_Blended(Font, AValue.c_str(), blackColor);

	TTF_CloseFont(Font);

	SDL_Surface* Flag = IMG_Load((FLAGS_PATH + ACharCode + FLAG_EXT).c_str());
	SDL_Surface* Rub = IMG_Load((FLAGS_PATH + (std::string)"RUB" + FLAG_EXT).c_str());

	Line = SDL_CreateRGBSurface(
				0, 
				LeftText->w + Flag->w + EqualText->w + RightText->w + Rub->w, 
				std::max({LeftText->h, Flag->h, EqualText->h, RightText->h, Rub->h}),
				32,
				0, 0, 0, 0
				);
	SDL_FillRect(Line, NULL, SDL_MapRGB(Line->format, 0xFF, 0xFF, 0xFF));

	SDL_Rect iRect;
	iRect.x = 0;
	iRect.y = 0;
	iRect.w = LeftText->w;
	iRect.h = LeftText->h;

	SDL_BlitSurface(LeftText, NULL, Line, &iRect);
	iRect.x += LeftText->w;
	SDL_BlitSurface(Flag, NULL, Line, &iRect);
	iRect.x += Flag->w;
	SDL_BlitSurface(EqualText, NULL, Line, &iRect);
	iRect.x += EqualText->w;
	SDL_BlitSurface(RightText, NULL, Line, &iRect);
	iRect.x += RightText->w;
	SDL_BlitSurface(Rub, NULL, Line, &iRect);

	// free temp surfaces
	SDL_FreeSurface(LeftText);
	SDL_FreeSurface(EqualText);
	SDL_FreeSurface(RightText);
	SDL_FreeSurface(Flag);
	SDL_FreeSurface(Rub);
}


CValuteEntry::~CValuteEntry()
{
	if (Line) {
		SDL_FreeSurface(Line);
		Line = nullptr;
	}
}
