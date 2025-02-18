#include "InputManager.h"
#include "Presenter.h"

bool InputManager::m_drag = bool();
bool InputManager::m_mouseIsPressed = bool();
bool InputManager::m_keyUpPressed = bool();
bool InputManager::m_keyDownPressed = bool();
bool InputManager::m_keyLeftPressed = bool();
bool InputManager::m_keyRightPressed = bool();
bool InputManager::m_mouseIsDoubleClicked = bool();
bool InputManager::m_mouseOnClick = bool();
bool InputManager::m_mouseOnRelease = bool();
bool InputManager::m_mouseIsPressedPrevFrame = bool();
bool InputManager::m_mouseIsHolded = bool();
int2 InputManager::m_mouseCoor = int2();
const Uint8* InputManager::m_keyboardState = nullptr;

InputManager::InputManager()
{
    m_scroll = 0;
}

InputManager::~InputManager()
{
    delete m_keyboardState;
}

void InputManager::setMouseMultiply(float2 multiplier)
{
    m_mouseMultiply.x = multiplier.x;
    m_mouseMultiply.y = multiplier.y;
}

void startDrag(void* handleInput)
{
    InputManager* inputManager = (InputManager*)handleInput;

    inputManager->m_drag = true;
}

void stopDrag(void* handleInput)
{
    InputManager* inputManager = (InputManager*)handleInput;

    inputManager->m_drag = false;
}

int event_filter(void* input, SDL_Event* event)
{
    if (event->type == SDL_MOUSEBUTTONDOWN)
    {
        startDrag(input);
    }
    if (event->type == SDL_MOUSEBUTTONUP)
    {
        stopDrag(input);
    }

    return 1;
}

void InputManager::handleInput()
{
    m_mouseIsPressed = false;
    m_mouseIsDoubleClicked = false;
    m_keyUpPressed = false;
    m_keyDownPressed = false;
    m_keyLeftPressed = false;
    m_keyRightPressed = false;

    SDL_SetEventFilter(&event_filter, (void*)this);
	
    while (SDL_PollEvent(&m_event))
    {
        switch (m_event.type)
        {
        case SDL_MOUSEMOTION:
            SDL_GetMouseState(&(m_mouseCoor.x), &(m_mouseCoor.y));

            m_mouseCoor.x *= m_mouseMultiply.x;
            m_mouseCoor.y *= m_mouseMultiply.y;
			
            break;
        case SDL_MOUSEBUTTONDOWN:
            if (m_event.button.button == SDL_BUTTON_LEFT)
            {
                m_mouseIsPressed = true;
            }

            break;
        case SDL_KEYDOWN:
            switch (m_event.key.keysym.sym)
            {
            case SDLK_UP:
                m_keyUpPressed = true;
                break;

            case SDLK_DOWN:
                m_keyDownPressed = true;
                break;

            case SDLK_LEFT:
                m_keyLeftPressed = true;
                break;

            case SDLK_RIGHT:
                m_keyRightPressed = true;
                break;
            }
        }
    }
	
    m_keyboardState = SDL_GetKeyboardState(NULL);

    m_scroll = 0;

    switch (m_event.wheel.type)
    {
    case SDL_MOUSEWHEEL:
        m_scroll = m_event.wheel.y;
        break;
    default:
        break;
    }

    m_event.wheel = SDL_MouseWheelEvent();

    if (m_mouseIsPressed)
    {
        if (!m_mouseIsPressedPrevFrame)
        {
            m_mouseOnClick = true;
        }
        else
        {
            m_mouseOnClick = false;
        }

        m_mouseIsHolded = true;
    }
    else
    {
        m_mouseIsPressedPrevFrame = false;
        m_mouseOnClick = false;
    }
}

bool InputManager::mouseIsPressed()
{
    return m_mouseIsPressed;
}

bool InputManager::mouseIsHolded()
{
    return m_mouseIsHolded;
}

bool InputManager::keyUpIsDown()
{
    
    return m_keyUpPressed;
}

bool InputManager::keyDownIsDown()
{
    return m_keyDownPressed;
}

bool InputManager::keyLeftIsDown()
{
    return m_keyLeftPressed;
}

bool InputManager::keyRightIsDown()
{
    return m_keyRightPressed;
}

bool isMouseInRect(SDL_Rect rect)
{
    return MouseIsInRect(InputManager::m_mouseCoor, rect);
}

bool mouseIsPressed()
{
    return InputManager::mouseIsPressed();
}

bool isAnyKeyPressed()
{
    int numOfKeys = 322;

    for (int i = 0; i < numOfKeys; i++)
    {
        if (InputManager::m_keyboardState[i])
        {
            return true;
        }
    }
    return false;
}

bool keyUpIsDown()
{
    return InputManager::keyUpIsDown();
}

bool keyDownIsDown()
{
    return InputManager::keyDownIsDown();
}

bool keyLeftIsDown()
{
    return InputManager::keyLeftIsDown();
}

bool keyRightIsDown()
{
    return InputManager::keyRightIsDown();
}
