#include "sdltest2.h"

void SDLTest2::OnCleanup() {
	if (Renderer) {
		SDL_DestroyRenderer(Renderer);
		Renderer = NULL;
	}

	if (Window) {
		SDL_DestroyWindow(Window);
		Window = NULL;
	}

	if (PrimarySurface) {
		SDL_FreeSurface(PrimarySurface);
		PrimarySurface = NULL;
	}

	SDL_Quit();
}
