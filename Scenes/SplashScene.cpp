#include "SplashScene.h"

SplashScene::SplashScene(SceneManager& sceneManager)
    : BaseScene { sceneManager }
    , m_dst { 10, 10, 50, 50 } {
}

void SplashScene::update() {
    const Keyboard& keyboard = getSharedContext().keyboard;

    if (keyboard.checkKeyState(SDL_SCANCODE_LEFT, Keyboard::KeyState::kHold)) {
        m_dst.x -= 5;
    } else if (keyboard.checkKeyState(SDL_SCANCODE_RIGHT, Keyboard::KeyState::kHold)) {
        m_dst.x += 5;
    } else if (keyboard.checkKeyState(SDL_SCANCODE_UP, Keyboard::KeyState::kHold)) {
        m_dst.y -= 5;
    } else if (keyboard.checkKeyState(SDL_SCANCODE_DOWN, Keyboard::KeyState::kHold)) {
        m_dst.y += 5;
    }

    if (keyboard.checkKeyState(SDL_SCANCODE_ESCAPE, Keyboard::KeyState::kPress)) {
        removeAllScenes();
    }

    if (keyboard.checkKeyState(SDL_SCANCODE_RETURN, Keyboard::KeyState::kPress)) {
        createScene(SceneType::kTitle);
    }
}

void SplashScene::render() {
    SDL_Renderer& renderer = getSharedContext().renderer;
    SDL_SetRenderDrawColor(&renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(&renderer, &m_dst);
}

void SplashScene::onEnter() {
    std::cout << "Entering Splash Scene \n";
}

void SplashScene::onExit() {
    std::cout << "Exiting Splash Scene \n";
}
