#include "sdltest2.h"

SDLTest2 SDLTest2::Instance;

SDLTest2::SDLTest2() {
	Window = NULL;
	Renderer = NULL;
	PrimarySurface = NULL;

	Running = true;
}

int SDLTest2::OnExecute(int argc, char* args[]) {
	if (OnInit() == false) {
		return -1;
	}

	SDL_Event Event;
	
	while (Running) {
		while (SDL_PollEvent(&Event)) {
			OnEvent(&Event);
		}

		OnLoop();
		OnRender();

		SDL_Delay(1); // Breath
	}

	OnCleanup();

	return 0;
}

void SDLTest2::ApplySurface(int x, int y, SDL_Texture *tex, SDL_Renderer *rend) {
	SDL_Rect pos;
	pos.x = x;
	pos.y = y;

	SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
	SDL_RenderCopy(Renderer, tex, NULL, &pos);
}

SDLTest2* SDLTest2::GetInstance() {
	return &SDLTest2::Instance;
}

int SDLTest2::GetWindowWidth() {
	return WindowWidth;
}

int SDLTest2::GetWindowHeight() {
	return WindowHeight;
}

int main(int argc, char* args[]) {
	return SDLTest2::GetInstance()->OnExecute(argc, args);
}