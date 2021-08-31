#include <iostream>
#include "SDL2/SDL.h"

#include "engine.h"

namespace IGQ{

    Engine* Engine::mInstance = nullptr;

    Engine::Engine() : mIsRunning(false){
        getInfo();
    }

    Engine& Engine::instance(){
        if(!mInstance){
            mInstance = new Engine();
        }
        return *mInstance;
    }

    void Engine::getInfo(){
        #ifdef IGQ_CONFIG_DEBUG
            std::cout << "Configuration Debug" << std::endl;
        #endif
        #ifdef IGQ_CONFIG_RELEASE
            std::cout << "Configuration Release" << std::endl;
        #endif
        #ifdef IGQ_PLATFORM_WINDOWS
            std::cout << "Platform Windows" << std::endl;
        #endif
        #ifdef IGQ_PLATFORM_LINUX
            std::cout << "Platform Linux" << std::endl;
        #endif
        #ifdef IGQ_PLATFORM_MAC
            std::cout << "Platform Mac" << std::endl;
        #endif
    }

    bool Engine::initialize() {
        bool ret = false;

        if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
            std::cout << "Error initializing SDL2: " << SDL_GetError() << std::endl;
        }
        else {
            SDL_version version;
            SDL_VERSION(&version);

            if(mWindow.create()){
                ret = true;
                mIsRunning = true;
            }
        }

        if(!ret){
            std::cout << "Engine initialization failed. Shutting down\n" << std::endl;
            shutDown();
        }

        return ret;
    }

    void Engine::shutDown() {
        mIsRunning = false;
        mWindow.shutDown();
        SDL_Quit();
    }

    void Engine::run(){
        if(initialize()){
            while(mIsRunning){
                mWindow.pumpEvents();
            }

            shutDown();
        }
    }
}