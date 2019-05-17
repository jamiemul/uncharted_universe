#pragma once
#include <iostream>
#include "../SharedContext.h"
#include "SceneType.h"

class SceneManager;

class BaseScene {
public:

    BaseScene(SceneManager& sceneManager);
    virtual ~BaseScene() = default;

    virtual void update()  = 0;
    virtual void render()  = 0;
    virtual void onEnter() = 0;
    virtual void onExit()  = 0;

protected:
    const SharedContext& getSharedContext() const;

    void createScene(const SceneType sceneType);
    void removeCurrentScene();
    void removeAllScenes();

private:
    SceneManager& m_sceneManager;
};
