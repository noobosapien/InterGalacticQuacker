#include "SDL2/SDL.h"

#include "engine.h"
#include "log.h"

namespace IGQ{

    Engine* Engine::mInstance = nullptr;

    Engine::Engine() : mIsRunning(false), mIsInitialized(false){
    }

    Engine& Engine::instance(){
        if(!mInstance){
            mInstance = new Engine();
        }
        return *mInstance;
    }

    void Engine::getInfo(){
        IGQ_TRACE("IGQ Engine v{}.{}", 0, 1);
        #ifdef IGQ_CONFIG_DEBUG
            IGQ_DEBUG("Configuration Debug");
        #endif
        #ifdef IGQ_CONFIG_RELEASE
            IGQ_DEBUG("Configuration Release");
        #endif
        #ifdef IGQ_PLATFORM_WINDOWS
            IGQ_WARN("Platform Windows");
        #endif
        #ifdef IGQ_PLATFORM_LINUX
            IGQ_WARN("Platform Linux");
        #endif
        #ifdef IGQ_PLATFORM_MAC
            IGQ_WARN("Platform Mac");
        #endif
    }

    bool Engine::initialize() {
        bool ret = false;
        IGQ_ASSERT(!mIsInitialized, "Calling Engine::initialize() more than once");

        if(!mIsInitialized){
            mLogmanager.Initialize();
            getInfo();

            if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
                IGQ_ERROR("Error initializing SDL2: {}", SDL_GetError());
            }
            else {
                SDL_version version;
                SDL_VERSION(&version);

                if(mWindow.create()){
                    ret = true;
                    mIsInitialized = true;
                    mIsRunning = true;
                }
            }

            if(!ret){
                IGQ_ERROR("Engine initialization failed. Shutting down\n");
                shutDown();
            }

        }
        return ret;
        
    }

    void Engine::shutDown() {
        mIsRunning = false;
        mIsInitialized = false;
        mWindow.shutDown();
        SDL_Quit();
        mLogmanager.shutDown();
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