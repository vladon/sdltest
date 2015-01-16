#include "sdltest2.h"
#include "CValuteEntry.h"

bool SDLTest2::OnInit() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		return false;
	}

	// SDL_image init
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) && imgFlags)) {
		return false;
	}

	// SDL_ttf init
	if (TTF_Init() == -1) {
		return false;
	}

	if ((Window = SDL_CreateWindow("SDL Test 2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WindowWidth, WindowHeight, SDL_WINDOW_SHOWN)) == NULL) {
		return false;
	}

	PrimarySurface = SDL_GetWindowSurface(Window);

	SDL_FillRect(PrimarySurface, NULL, SDL_MapRGB(PrimarySurface->format, 0xFF, 0xFF, 0xFF));

	LoadExchangeRates();
	PostExchangeRates();

	return true;
}
