#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <vector>
#include "CValuteEntry.h"

#define FONT_FILENAME "files/consola.ttf"
#define FONT_SIZE 16
#define RUB_CHARCODE "RUB"
#define FLAGS_PATH "files/flags/"
#define FLAG_EXT ".png"
#define RUB_CHARCODE "RUB"
#define POST_URL "http://maclaud.pin-magazin.com/log.php"

class SDLTest2 { 
	private:
		static SDLTest2 Instance;

		bool Running;

		SDL_Window* Window;
		SDL_Surface* PrimarySurface;
		TTF_Font* Font;

		static const int WindowWidth = 600;
		static const int WindowHeight = 800;

		// Valutes
		std::vector<CValuteEntry*> ValuteEntries;

	private:
		void ApplySurface(SDL_Surface* surface, int x, int y);
		void LoadExchangeRates();
		void PostExchangeRates();

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
};
