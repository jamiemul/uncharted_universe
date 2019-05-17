#include "SceneManager.h"
#include "Scenes/SplashScene.h"
#include "Scenes/TitleScene.h"

SceneManager::SceneManager(const SharedContext& context) : m_sharedContext { context } {
    // Register all Scenes
    registerScene<SplashScene>(SceneType::kSplash);
    registerScene<TitleScene>(SceneType::kTitle);
    createScene(SceneType::kSplash);
}

void SceneManager::update() const {
    if (!m_sceneStack.empty()) {
        m_sceneStack.back().second->update();
    }
}

void SceneManager::render() const {
    if (!m_sceneStack.empty()) {
        m_sceneStack.back().second->render();
    }
}

void SceneManager::removeScene() {
    m_sceneStack.back().second->onExit();
    m_sceneStack.pop_back();
}

void SceneManager::createScene(const SceneType sceneType) {
    // Check if scene has been registered in the scene factory
    const auto& sf = m_sceneFactory.find(sceneType);
    if (sf != m_sceneFactory.end()) {
        // Check if scene already exists in the scene stack
        const auto& ss = std::find_if(m_sceneStack.begin(), m_sceneStack.end(), [sceneType](const auto& ss) { return (ss.first == sceneType);});
        if (ss == m_sceneStack.end()) {
            m_sceneStack.emplace_back(std::pair(sceneType, sf->second()));
            m_sceneStack.back().second->onEnter();
        }
    }
}

void SceneManager::removeAllScenes() {
    while (!m_sceneStack.empty()) {
        m_sceneStack.back().second->onExit();
        m_sceneStack.pop_back();
    }
}

bool SceneManager::isSceneStackEmpty() const{
    return m_sceneStack.empty();
}

const SharedContext& SceneManager::getSharedContext() const {
    return m_sharedContext;
}