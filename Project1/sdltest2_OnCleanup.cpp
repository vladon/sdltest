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

	if (Surf_Display) {
		SDL_FreeSurface(Surf_Display);
		Surf_Display = NULL;
	}

	if (Surf_Test) {
		SDL_FreeSurface(Surf_Test);
		Surf_Test = NULL;
	}

	SDL_Quit();
}
