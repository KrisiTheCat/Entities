#pragma once

#include <cmath>
#include <string>
#include <float.h>
#include <utility>

#include <SDL.h>
#include <SDL_TTF.h>

#include "defines.h"

SDL_Texture* LoadTexture(string configFile, SDL_Renderer* renderer);
bool MouseIsInRect(int2 coor, SDL_Rect rect);
bool MouseIsInCircle(int2 coor, int2 center, int radius);
bool MouseIsInEllipse(int2 point, int2 elipseCenter, int2 elipseRadius);
bool MouseIsInTriangle(int2 point, int2 trianglePoint1, int2 trianglePoint2, int2 trianglePoint3);