#include <iostream>
#include <lexus.h>

int main(int argc, char** argv) {
    Lexus::Command command(argc, argv);

    if (command.isHelp()) {
        std::cout << Lexus::Command::getHelpText() << std::endl;
        return 0;
    }

    if (command.isVersion()) {
        std::cout << Lexus::Command::getVersionText() << std::endl;
        return 0;
    }

    if (command.getConfigFile() == nullptr) {
        std::cout << "Config file is required" << std::endl;
        return -1;
    }

    Lexus::Config config(command.getConfigFile()->c_str());

    return 0;
}
