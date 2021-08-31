#include <iostream>
#include "IGQengine/engine.h"

int main(){
    IGQ::getInfo();
    IGQ::initialize();
    IGQ::shutDown();

#ifdef IGQ_PLATFORM_WINDOWS
    system("pause");
#endif

    return 0;
}