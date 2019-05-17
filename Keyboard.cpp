#include "Keyboard.h"

Keyboard::Keyboard() :
        m_currentState { },
        m_previousState{ },
        m_keyboardState{ SDL_GetKeyboardState(nullptr) } {
}

void Keyboard::update() {
    m_previousState = m_currentState;
    memcpy(m_currentState.data(), m_keyboardState, SDL_NUM_SCANCODES);
}

bool Keyboard::checkKeyState(SDL_Scancode scanCode, KeyState keystate) const {
    KeyState currentKeyState = KeyState::kNone;
    if (m_previousState[scanCode]) {
        currentKeyState = !m_currentState[scanCode] ? KeyState::kRelease : KeyState::kHold;
    } else if (m_currentState[scanCode]) {
        currentKeyState = KeyState::kPress;
    }
    return currentKeyState == keystate;
}