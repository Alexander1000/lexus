#include <iostream>
#include <lexus.h>
#include <io-buffer.h>
#include <yaml-parser.h>

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

    IOBuffer::IOFileReader fileReader(*command.getConfigFile());
    IOBuffer::CharStream charStream(&fileReader);
    YamlParser::Stream yamlStream(&charStream);
    YamlParser::Decoder decoder(&yamlStream);

    YamlParser::Element* valuesObject = decoder.parse();

    return 0;
}
