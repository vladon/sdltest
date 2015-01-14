#include "CSurface.h"

CSurface::CSurface()
{
}

SDL_Surface* CSurface::OnLoad(char* File) {
	return SDL_LoadBMP(File);
}

bool CSurface::OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y) {
	if ((Surf_Dest == NULL) || (Surf_Src == NULL)) {
		return false;
	}

	SDL_Rect DestR;

	DestR.x = X;
	DestR.y = Y;

	SDL_BlitSurface(Surf_Src, NULL, Surf_Dest, &DestR);

	return true;
}