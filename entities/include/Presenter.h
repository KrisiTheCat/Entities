#pragma once 

#include <iomanip>

#include <SDL_TTF.h>

#include "Writer.h"
#include "Engine.h"

using namespace std;

/** A struct that has pointer of type rect and texture being
	later used to draw an object on the screen.

	The point of this struct is to minimize the use of classes
	in the client
*/

class Presenter
{
public:
	static SDL_Window* m_main_window;
	static SDL_Renderer* m_main_renderer;
	
	static unsigned int m_SCREEN_WIDTH;
	static unsigned int m_SCREEN_HEIGHT;

	Writer m_writer;

	void init();
	void update();
	void draw();

	SDL_Renderer* getRenderer();

	static void drawObject(SDL_Texture* texture);
	static void drawObject(Drawable& drawable);
	static void drawObject(DrawableWithOpacity& drawable);

	static void drawObjectRotated(SDL_Texture* texture, Rotatable rotate);
	static void drawObjectRotated(Drawable& drawable, Rotatable rotate);
	static void drawObjectRotated(DrawableWithOpacity& drawable, Rotatable rotate);
	
private:
	int2 screenCenter;

	void improveRenderer();
};

namespace
{
	template <typename T>
	void drawObject(T& t)
	{
		Presenter::drawObject(t);
	}
	template <typename T>
	void drawObjectRotated(T& t, Rotatable rotate)
	{
		Presenter::drawObjectRotated(t, rotate);
	}

	SDL_Texture* loadTexture(string path)
	{
		return LoadTexture(path, Presenter::m_main_renderer);
	}
}