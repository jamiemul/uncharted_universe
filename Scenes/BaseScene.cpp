#include "BaseScene.h"
#include "../SceneManager.h"

BaseScene::BaseScene(SceneManager& sceneManager) 
    : m_sceneManager { sceneManager } {
}

const SharedContext& BaseScene::getSharedContext() const{
    return m_sceneManager.getSharedContext();
}

void BaseScene::createScene(const SceneType sceneType) {
    m_sceneManager.createScene(sceneType);
}

void BaseScene::removeCurrentScene() {
    m_sceneManager.removeScene();
}

void BaseScene::removeAllScenes() {
    m_sceneManager.removeAllScenes();
}