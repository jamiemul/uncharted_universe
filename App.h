#pragma once
#include <SDL.h>
#include "SDLUnique.h"
#include "Keyboard.h"
#include "FPSLimiter.h"
#include "Data.h"
#include "SceneManager.h"
#include "SharedContext.h"

class App {
public:
    App();
    bool setup();
    void run();

private:
    void update();
    void render();

    // GAME FUNCTIIONS

    bool            m_quit;
    bool            m_initSDL;
    SDL2u_Window    m_window;
    SDL2u_Renderer  m_renderer;
    Keyboard        m_keyboard;
    FPSLimiter<>    m_fpsLimiter;
    SceneManager    m_sceneManager;
    SDL2u_Texture   m_texture;
};
