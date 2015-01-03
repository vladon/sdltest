// Use SDL and standard IO
#include <SDL.h>
#include <stdio.h>

// some constants
const int WIN_WIDTH = 640;
const int WIN_HEIGHT = 480;

int main(int argc, char* args[]) {
	
	// window
	SDL_Window* window = NULL;

	// surface
	SDL_Surface* surface = NULL;

	// Init SDL, only video
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else {

	}
}