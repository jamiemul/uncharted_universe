#include "App.h"
#include "TextureLoader.h"

App::App() : 
    m_quit         { false },
    m_initSDL      { SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) == 0 },            
    m_window       { SDL_CreateWindow("SDL_Project", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 480, 0) },
    m_renderer     { SDL_CreateRenderer(m_window.get(), -1, SDL_RENDERER_ACCELERATED) },
    m_keyboard     { }, 
    m_fpsLimiter   { },
    m_sceneManager { SharedContext{ m_keyboard, *m_renderer }} {
}

bool App::setup() {
    bool setUpSuccess = false;
    if (m_initSDL && m_window && m_renderer) {
        // Load Texture;
        //m_texture = TextureLoader::create1x1Texture(m_renderer.get());
        //m_texture = TextureLoader::loadTexture(m_renderer.get(), "../Assets/Textures/tetris.bmp");
        //SDL_SetRenderDrawColor(m_renderer.get(), Color::kCfb.r, Color::kCfb.g, Color::kCfb.b, Color::kCfb.a);
        setUpSuccess = true;
    }
    return setUpSuccess;
}

void App::run() {
    while (!m_quit) {
        if (!m_sceneManager.isSceneStackEmpty()) {
            update();
            render();
            m_fpsLimiter.run();
        } else {
            m_quit = true;
        }
    }
    SDL_Quit();
}

void App::update() {
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
            m_quit = true;
        }
    }
    m_keyboard.update();
    m_sceneManager.update();
}

void App::render() {
    SDL_SetRenderDrawColor(m_renderer.get(), Color::kCfb.r, Color::kCfb.g, Color::kCfb.b, Color::kCfb.a);
    SDL_RenderClear(m_renderer.get());
    m_sceneManager.render();
    SDL_RenderPresent(m_renderer.get());
}