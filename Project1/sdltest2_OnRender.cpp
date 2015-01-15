#include "sdltest2.h"

void SDLTest2::OnRender() {
	SDL_RenderClear(Renderer);

	SDL_RenderPresent(Renderer);
}

