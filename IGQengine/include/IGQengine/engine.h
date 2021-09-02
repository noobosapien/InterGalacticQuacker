#pragma once

#include "core/window.h"
#include "managers/logmanager.h"

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
            bool mIsInitialized;

            [[nodiscard]]bool initialize();
            void shutDown();

            void getInfo();

            //managers
            managers::LogManager mLogmanager;

    };
}