#pragma once

#include <iostream>
#include <string>

#include <vector>
#include <SDL.h>

/*! \class defines
    \brief A header that contains structures and enumerators
    They are used for the different type of game states, ores and more
*/
using namespace std;
///A user-defined function similar to std::cout but giving more information
/**
*   @code
*   #define D(x) cerr << #x << " = " << (x) << " | " << __LINE__ << endl;
*   @endcode
*/
///A user-defined function similar to D(x) but more advanced
/**
*   @code
*   #define Dex(x) cerr << #x << " = " << (x) << " | " << __LINE__ << " " << __FILE__ << endl;
*   @endcode
*/
#define D(x) cerr << #x << " = " << (x) << " | " << __LINE__ << endl;
#define Dex(x) cerr << #x << " = " << (x) << " | " << __LINE__ << " " << __FILE__ << endl;
#define __FILE_NAME__ (strrchr(__FILE__, '\\' ) ? strrchr(__FILE__, '\\') + 1 : __FILE__)

static string UI_FOLDER = "UI\\";
static string MENU_FOLDER = "menu\\";
static string FRUITS_FOLDER = "fruits\\";
static string SPLASHES_FOLDER = "splashes\\";
static string IMG_FOLDER = "img\\";
static string CONFIG_FOLDER = "config\\";
static string FONT_FOLDER = "ttf\\";
static string CONFIG_MANAGER_FOLDER = "configManager\\";
static string SOUND_FOLDER = "music\\";
static string TITLE_SCREEN_FOLDER = "titleScreen\\";
static string WIN_SCREEN_FOLDER = "winScreen\\";
static string GAME_FOLDER = "game\\";

struct int2
{
    int x = 0;
    int y = 0;

    void reset()
    {
        x = 0;
        y = 0;
    }

    template <typename T>
    void operator*=(T a)
    {
        x *= a;
        y *= a;
    }

    template <typename T>
    void operator/=(T a)
    {
        x /= a;
        y /= a;
    }

    template <typename T>
    int2 operator*(T a)
    {
        x *= a;
        y *= a;

        return *this;
    }

    template <typename T>
    int2 operator/(T a)
    {
        x /= a;
        y /= a;

        return *this;
    }

    template <typename T>
    bool operator!=(T a)
    {
        return (x != a || y != a);
    }


    int2 operator+(int2 a)
    {
        int2 b;
        b.x = x + a.x;
        b.y = y + a.y;

        return b;
    }

    bool operator==(const int2 a) const
    {
        return (x == a.x && y == a.y);
    }

};

struct float2
{
    float x = 0;
    float y = 0;

    void reset()
    {
        x = 0;
        y = 0;
    }

    void operator=(int2 a)
    {
        x = a.x;
        y = a.y;
    }

    void operator+=(float2 a)
    {
        x += a.x;
        y += a.y;
    }

    void operator-=(float2 a)
    {
        x -= a.x;
        y -= a.y;
    }

    template <typename T>
    void operator*=(T a)
    {
        x *= a;
        y *= a;
    }

    template <typename T>
    void operator/=(T a)
    {
        x /= a;
        y /= a;
    }

    template <typename T>
    float2 operator*(T a)
    {
        x *= a;
        y *= a;

        return *this;
    }

    template <typename T>
    float2 operator/(T a)
    {
        x /= a;
        y /= a;

        return *this;
    }

    // used in the animator

    template <typename T>
    bool operator!=(T a)
    {
        return (x != a || y != a);
    }

    template <typename T>
    bool operator>(T a)
    {
        return (x > a || y > a);
    }

    template <typename T>
    bool operator<(T a)
    {
        return (x < a || y < a);
    }

    template <typename T>
    bool operator==(T a)
    {
        return (x == a && y == a);
    }
};

enum class HITBOX
{
    NONE = 0,
    RECT = 1,
    TRIANGLE = 2,
    CIRCLE = 3,
    OVAL = 4
};

enum class FONT
{
    NONE = 0,
    ASSASIN = 1
};

enum class COLOR
{
    NONE = 0,
    LIGHT = 1,
    DARK = 2
};

enum class BEHAVIOR_TYPE
{
    NONE = 0,
    HOSTILE = 1,
    FRIENDLY = 2
};

enum class ATTACKING_STATE
{
    NONE = 0,
    ATTACK = 1
};

struct Drawable
{
    SDL_Texture* texture = nullptr;
    SDL_Rect rect = { 0 }; /// The rect where we draw
};

struct DrawableForMenu : public Drawable
{
    SDL_Texture* glowTexture = nullptr;
};

struct Rotatable
{
    int angle = 0;
    SDL_RendererFlip flip = SDL_FLIP_NONE;
};

struct DrawableWithOpacity : public Drawable
{
    int opacity = 0;
    int changePerFrame = 0;
};

enum class SOUND
{
    NONE = 0,
    BACKGROUND = 1,
    SLICE_MUSIC = 2,
    BOMB_EXPLOSION = 3
};