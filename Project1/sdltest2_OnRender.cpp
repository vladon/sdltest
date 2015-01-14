#include "sdltest2.h"
#include "CSurface.h"

void SDLTest2::OnRender() {
	CSurface::OnDraw(Surf_Display, Surf_Test, 0, 0);

	SDL_RenderClear(Renderer);

	SDL_RenderPresent(Renderer);
}

