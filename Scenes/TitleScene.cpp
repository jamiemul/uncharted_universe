#include "TitleScene.h"

TitleScene::TitleScene(SceneManager& sceneManager) 
    : BaseScene { sceneManager } {
}

void TitleScene::update() {
    const Keyboard& keyboard = getSharedContext().keyboard;
    if (keyboard.checkKeyState(SDL_SCANCODE_RETURN, Keyboard::KeyState::kPress)) {
        removeCurrentScene();
    }
}

void TitleScene::render() {
}

void TitleScene::onEnter() {
    std::cout << "Entering Title Scene \n";
}

void TitleScene::onExit() {
    std::cout << "Exiting Title Scene \n";
}
