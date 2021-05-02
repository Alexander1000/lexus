#include <iostream>
#include <lexus.h>
#include <io-buffer.h>
#include <yaml-parser.h>

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

    IOBuffer::IOFileReader fileReader(*config.getConfigFile());
    IOBuffer::CharStream charStream(&fileReader);
    YamlParser::Stream yamlStream(&charStream);
    YamlParser::Decoder decoder(&yamlStream);

    YamlParser::Element* valuesObject = decoder.parse();

    return 0;
}
