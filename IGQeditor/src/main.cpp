#include <iostream>
#include "IGQengine/engine.h"

int main(){

    IGQ::Engine& engine = IGQ::Engine::instance();

    engine.run();

    std::cout << "Press enter to continue...";
    std::cin.ignore();

    return 0;
}