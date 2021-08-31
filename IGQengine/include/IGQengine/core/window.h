#pragma once

struct SDL_Window;

namespace IGQ::core{
    class Window{
        public:
        Window();
        ~Window();

        bool create();
        void shutDown();

        void pumpEvents();

        private:
        SDL_Window* mWindow;
    };
}