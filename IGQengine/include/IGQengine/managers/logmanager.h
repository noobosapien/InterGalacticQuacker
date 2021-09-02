#pragma once

namespace IGQ::managers{

    class LogManager{
        public:
        LogManager() = default;
        ~LogManager() = default;

        void Initialize();
        void shutDown();

    };
}