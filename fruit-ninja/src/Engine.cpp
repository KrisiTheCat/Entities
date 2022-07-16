#include "Engine.h"

SDL_Texture* LoadTexture(string configFile, SDL_Renderer* renderer)
{
    SDL_Texture* texture = nullptr;

    try
    {
        configFile = IMG_FOLDER + configFile;

        SDL_Surface* loadingSurface = SDL_LoadBMP(configFile.c_str());

        texture = SDL_CreateTextureFromSurface(renderer, loadingSurface);

        SDL_FreeSurface(loadingSurface);

        if (texture == nullptr)
        {
            throw (-1);
        }
    }
    catch (int i)
    {
        if (i < 0)
        {
            cout << "NO TEXTURE LOADED: " << configFile << endl;

            configFile = IMG_FOLDER + "textureNotLoaded.bmp";

            SDL_Surface* loadingSurface = SDL_LoadBMP(configFile.c_str());
            texture = SDL_CreateTextureFromSurface(renderer, loadingSurface);
            SDL_FreeSurface(loadingSurface);
        }
    }

    return texture;
}

bool MouseIsInRect(int2 coor, SDL_Rect rect)
{
    if (coor.x >= rect.x && coor.x <= rect.x + rect.w && coor.y >= rect.y && coor.y <= rect.y + rect.h)
    {
        return true;
    }

    return false;
}

bool MouseIsInCircle(int2 coor, int2 center, int radius)
{
    int2 dist;
	
    dist.x = coor.x - center.x;
    dist.y = coor.y - center.y;

	if (dist.x * dist.x + dist.y * dist.y <= radius * radius)
	{
		return true;
	}

	return false;
}

bool MouseIsInEllipse(int2 point, int2 elipseCenter, int2 elipseRadius)
{
	int2 dist;
	
	dist.x = point.x - elipseCenter.x;
	dist.y = point.y - elipseCenter.y;
	
	if (dist.x * dist.x + dist.y * dist.y <= elipseRadius.x * elipseRadius.x 
        + elipseRadius.y * elipseRadius.y)
	{
		return true;
	}
	
	return false;
}

bool MouseIsInTriangle(int2 point, int2 trianglePoint1, int2 trianglePoint2, int2 trianglePoint3)
{

    return false;
}

