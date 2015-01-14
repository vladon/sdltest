#include "sdltest2.h"

void SDLTest2::OnEvent(SDL_Event* Event) {
	if (Event->type == SDL_QUIT) {
		Running = false;
	}
}
