#pragma once
#include <SDL.h>
#include <SDL_ttf.h>

class SDLTest2 { 
	private:
		static SDLTest2 Instance;

		bool Running;

		SDL_Window* Window;
		SDL_Renderer* Renderer;
		SDL_Surface* PrimarySurface;

		static const int WindowWidth = 600;
		static const int WindowHeight = 800;

	public:
		SDLTest2();

		int OnExecute(int argc, char* args[]);

	public:
		bool OnInit();

		void OnEvent(SDL_Event* Event);

		void OnLoop();

		void OnRender();

		void OnCleanup();

	public:
		static SDLTest2* GetInstance();

		static int GetWindowWidth();
		static int GetWindowHeight();

		void ApplySurface(int x, int y, SDL_Texture *tex, SDL_Renderer *rend);
};
