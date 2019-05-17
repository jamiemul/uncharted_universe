#pragma once

#include <array>
#include <SDL_keyboard.h>

class Keyboard {
public:
    enum class KeyState : uint8_t {
        kNone, kHold, kPress, kRelease
    };

    Keyboard();
    void update();
    bool checkKeyState(SDL_Scancode scanCode, KeyState keyState) const;

private:
    const uint8_t* m_keyboardState;
    std::array<bool, SDL_NUM_SCANCODES> m_currentState;
    std::array<bool, SDL_NUM_SCANCODES> m_previousState;
};
