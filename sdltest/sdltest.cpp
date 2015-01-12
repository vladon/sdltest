// Use SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <curl\curl.h>

// some constants
const int WIN_WIDTH = 640;
const int WIN_HEIGHT = 480;

// functions
bool init();
void close();

// global vars
SDL_Window* gWindow = NULL;
SDL_Surface* gSurface = NULL;
SDL_Renderer* gRenderer = NULL;

SDL_Rect topViewport;

bool init()
{
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize. SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		gWindow = SDL_CreateWindow("SDL test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created. SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			gSurface = SDL_GetWindowSurface(gWindow);

			SDL_FillRect(gSurface, NULL, SDL_MapRGB(gSurface->format, 0xFF, 0xFF, 0xFF));

			SDL_UpdateWindowSurface(gWindow);
		}
	}

	return success;
}

void close()
{
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	SDL_Quit();
}

int main(int argc, char* args[]) 
{	
	if (!init())
	{
		printf("Failed to initialize.\n");
	}
	else
	{
		topViewport.x = 0;
		topViewport.y = 0;
		topViewport.w = WIN_WIDTH;
		topViewport.h = WIN_HEIGHT / 2;


		bool quit = false;

		SDL_Event e;

		while (!quit)
		{
			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}
			}

			SDL_UpdateWindowSurface(gWindow);
		}
	}

	close();

	return 0;
}