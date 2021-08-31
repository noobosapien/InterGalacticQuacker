#include <iostream>
#include "sdl2/SDL.h"

#include "engine.h"

namespace IGQ{

    void getInfo(){
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

    bool initialize() {
        bool ret = true;

        if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
            std::cout << "Error initializing SDL2: " << SDL_GetError() << std::endl;
            ret = false;
        }
        else {
            SDL_version version;
            SDL_VERSION(&version);

            std::cout << "SDL " << (int32_t)version.major << "." << (int32_t)version.minor << "." << 
                (int32_t)version.patch << std::endl;
        }

        return ret;
    }

    void shutDown() {
        SDL_Quit();
    }
}