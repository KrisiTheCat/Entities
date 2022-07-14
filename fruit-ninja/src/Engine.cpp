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

void write(string text, int2 coor, SDL_Renderer* renderer, int FONT_SIZE)
{
    SDL_Texture* texture;
    SDL_Surface* surface;
	
    SDL_Rect rect;
	
    SDL_Color fcolor;
	
    TTF_Font* font;

    string str = FONT_FOLDER + "AdventPro-ExtraLight.ttf";
    font = TTF_OpenFont(str.c_str(), FONT_SIZE);

    if (font == NULL)
    {
        fprintf(stderr, "error: font not found\n");
        exit(EXIT_FAILURE);
    }

    fcolor.r = 255;
    fcolor.g = 255;
    fcolor.b = 255;
    fcolor.a = 255;

    const char* t = text.c_str();

    surface = TTF_RenderText_Solid(font, t, fcolor);
    texture = SDL_CreateTextureFromSurface(renderer, surface);

    rect.w = surface->w;
    rect.h = surface->h;
    rect.x = coor.x;
    rect.y = coor.y;

    SDL_RenderCopy(renderer, texture, NULL, &rect);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}
