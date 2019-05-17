#pragma once
#include "BaseScene.h"

class SplashScene : public BaseScene {
public:
    SplashScene(SceneManager& sceneManager);
    
    void update() override;
    void render() override;
    void onEnter() override;
    void onExit() override;

private:
    SDL_Rect m_dst;
};