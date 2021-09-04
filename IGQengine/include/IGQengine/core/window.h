#pragma once

struct SDL_Window;
using SDL_GLContext = void*;

namespace IGQ::core{
    class Window{
        public:
        Window();
        ~Window();

        bool create();
        void shutDown();

        void pumpEvents();

        void beginRender();
        void endRender();

        private:
        SDL_Window* mWindow;
        SDL_GLContext mGLContext;
    };
}