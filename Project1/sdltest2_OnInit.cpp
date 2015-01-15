#include "sdltest2.h"
#include "CValuteEntry.h"

bool SDLTest2::OnInit() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		return false;
	}

	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
		return false;
	}

	if ((Window = SDL_CreateWindow("SDL Test 2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WindowWidth, WindowHeight, SDL_WINDOW_SHOWN)) == NULL) {
		return false;
	}

	PrimarySurface = SDL_GetWindowSurface(Window);

	if ((Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)) == NULL) {
		return false;
	}

	SDL_SetRenderDrawColor(Renderer, 0xFF, 0xFF, 0xFF, 0xFF);


	// load test bmp
	SDL_Surface* bmp = nullptr;
	if ((bmp = SDL_LoadBMP("files/flags/AMD.bmp")) == nullptr) {
		return false;
	}

	SDL_Texture* tex = SDL_CreateTextureFromSurface(Renderer, bmp);
	SDL_FreeSurface(bmp);

	if (tex == nullptr) {
		return false;
	}
	SDL_RenderCopy(Renderer, tex, NULL, NULL);


	return true;
}
