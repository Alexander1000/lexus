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

    if (command.getOutputDir() == nullptr) {
        std::cout << "Output dir is required" << std::endl;
        return -1;
    }

    if (command.getHeadersDir() == nullptr) {
        std::cout << "Headers dir is required" << std::endl;
        return -1;
    }

    Lexus::Config config(command.getConfigFile()->c_str());

    Lexus::Render render(&config, command.getOutputDir(), command.getHeadersDir());
    render.run();

    return 0;
}
