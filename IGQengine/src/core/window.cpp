#include "SDL2/SDL.h"
#include <iostream>

#include "core/window.h"
#include "engine.h"

namespace IGQ::core {

    Window::Window() : mWindow(nullptr){

    }

    Window::~Window(){
        if(mWindow){
            shutDown();
        }
    }

    bool Window::create(){
        mWindow = SDL_CreateWindow("IGQ", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);

        if(!mWindow){
            std::cout << "Error creating window: " << SDL_GetError() << std::endl;
            return false;
        }
        return true;
    }

    void Window::shutDown(){
        SDL_DestroyWindow(mWindow);
        mWindow = nullptr;
    }

    void Window::pumpEvents(){
        SDL_Event e;

        while(SDL_PollEvent(&e)){
            switch (e.type) {
            case SDL_QUIT:
                Engine::instance().quit();
                break;

            default:
                break;
            }
        }
    }
}