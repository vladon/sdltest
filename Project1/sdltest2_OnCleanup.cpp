#include "sdltest2.h"

void SDLTest2::OnCleanup() {
	if (PrimarySurface) {
		SDL_FreeSurface(PrimarySurface);
		PrimarySurface = nullptr;
	}

	if (Window) {
		SDL_DestroyWindow(Window);
		Window = nullptr;
	}

	if (Font) {
		TTF_CloseFont(Font);
		Font = nullptr;
	}
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}
