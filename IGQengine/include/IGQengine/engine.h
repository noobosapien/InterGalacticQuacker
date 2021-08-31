#pragma once

#include "core/window.h"

namespace IGQ{

    class Engine{
        public: 
            static Engine& instance();
            ~Engine() {}

            void run();
            inline void quit() { mIsRunning = false; }

        private:
            Engine();
            static Engine* mInstance;
            core::Window mWindow;
            bool mIsRunning;

            [[nodiscard]]bool initialize();
            void shutDown();

            void getInfo();

    };
}