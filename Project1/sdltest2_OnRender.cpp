#include "sdltest2.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

void SDLTest2::ApplySurface(SDL_Surface* surface, int x, int y) {
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;

	SDL_BlitSurface(surface, NULL, PrimarySurface, &offset);
}

void SDLTest2::OnRender() {
	int x = 0;
	int y = 0;

	for (auto &i : ValuteEntries) {
		x = (WindowWidth - i->Line->w) / 2;

		ApplySurface(i->Line, x, y);

		y += i->Line->h;
	}

	SDL_UpdateWindowSurface(Window);
}

