#include <iostream>
#include <lexus.h>

int main(int argc, char** argv) {
    Lexus::Config config(argc, argv);

    if (config.isHelp()) {
        std::cout << Lexus::Config::getHelpText() << std::endl;
        return 0;
    }

    if (config.isVersion()) {
        std::cout << Lexus::Config::getVersionText() << std::endl;
        return 0;
    }

    return 0;
}
