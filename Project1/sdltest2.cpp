#include "sdltest2.h"
#include <SDL_image.h>
#include <SDL_ttf.h>

SDLTest2 SDLTest2::Instance;

SDLTest2::SDLTest2() {
	Window = nullptr;
	PrimarySurface = nullptr;
	Font = nullptr;

	Running = true;

	ValuteEntries.clear();
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