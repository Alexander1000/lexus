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

    if (config.getConfigFile() == nullptr) {
        std::cout << "Config file is required" << std::endl;
        return -1;
    }

    return 0;
}
