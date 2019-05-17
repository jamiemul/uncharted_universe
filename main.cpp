#include "App.h"
#include <iostream>

int main(int argc, char* argv[]) {
    App app;
    if (app.setup()) {
        app.run();
    }
    return 0;
}