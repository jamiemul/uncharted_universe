#pragma once

#include<vector>
#include<unordered_map>
#include"SharedContext.h"
#include"Scenes/BaseScene.h"
#include"Scenes/SceneType.h"
#include<memory>

class SceneManager {
public:
    explicit SceneManager(const SharedContext& context);

    void update() const;
    void render() const;

    void removeScene();
    void createScene(const SceneType sceneType);
    void removeAllScenes();
    bool isSceneStackEmpty() const;
    const SharedContext& getSharedContext() const;

private:
    using SceneStack   = std::vector<std::pair<SceneType, std::unique_ptr<BaseScene>>>;
    using SceneFactory = std::unordered_map<SceneType, std::function<std::unique_ptr<BaseScene>(void)>>;
    
    SceneStack    m_sceneStack;
    SceneFactory  m_sceneFactory;
    SharedContext m_sharedContext;

    template <typename T> 
    void registerScene(const SceneType sceneType) {
        m_sceneFactory[sceneType] = [this]() {
            return std::make_unique<T>(*this);
        };
    }

};
