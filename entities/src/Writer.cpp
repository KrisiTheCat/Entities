#include "Writer.h"
#include "Presenter.h"

map<int, TTF_Font*> Writer::m_assasin = map<int, TTF_Font*>();
map<COLOR, SDL_Color> Writer::m_colors = map<COLOR, SDL_Color>();

Writer::Writer()
{

}

Writer::~Writer()
{

}

/*
* @return returns a pair, containing the with and height of the surface
*			also the texture itself
*/

pair<int2, SDL_Texture*> Writer::getText(string text, FONT fontName, COLOR colorName, int fontSize)
{
	TTF_Font* font;
	switch (fontName)
	{
	case FONT::ASSASIN:
		font = m_assasin.at(fontSize);
		break;
	default:
		font = nullptr;
	}

	const char* t = text.c_str();

	SDL_Surface* surface = TTF_RenderText_Blended(font, t, m_colors.at(colorName));
	SDL_Texture* texture = SDL_CreateTextureFromSurface(Presenter::m_main_renderer, surface);

	int2 size;
	size.x = surface->w;
	size.y = surface->h;

	pair<int2, SDL_Texture*> returnData
		= pair<int2, SDL_Texture*>(size, texture);

	SDL_FreeSurface(surface);
	
	return returnData;
}

void Writer::init()
{
	///In this function we create the main color values

	m_assasinLocation = FONT_FOLDER + "assasin.ttf";

	TTF_Font* m_font;

	for (int i = 11; i <= 72; i++)
	{
		m_font = TTF_OpenFont(m_assasinLocation.c_str(), i);
		m_assasin.insert(pair<int, TTF_Font*>(i, m_font));
	}

	SDL_Color color;

	color.a = Uint8(255);
	color.r = Uint8(255);
	color.g = Uint8(255);
	color.b = Uint8(255);

	m_colors.insert(pair<COLOR, SDL_Color>(COLOR::LIGHT, color));

	color.r = Uint8(0);
	color.g = Uint8(0);
	color.b = Uint8(0);

	m_colors.insert(pair<COLOR, SDL_Color>(COLOR::DARK, color));
}

pair<int2, SDL_Texture*> getText(string text, FONT fontName, COLOR colorName, int fontSize)
{
	return Writer::getText(text, fontName, colorName, fontSize);
}
