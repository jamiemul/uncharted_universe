#pragma once
#include "BaseScene.h"

class TitleScene : public BaseScene {
public:
    TitleScene(SceneManager& sceneManager);
    
    void update() override;
    void render() override;
    void onEnter() override;
    void onExit() override;

private:
};