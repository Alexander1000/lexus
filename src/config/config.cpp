#include <lexus.h>
#include <io-buffer.h>
#include <yaml-parser.h>
#include <string>
#include <map>
#include <iostream>

namespace Lexus
{
    Config::Config(const char* configFile)
    {
        this->scanConfigFile(configFile);
    }

    void Config::scanConfigFile(const char* configFile)
    {
        this->regs = new std::map<std::string, std::string>;

        IOBuffer::IOFileReader fileReader(configFile);
        IOBuffer::CharStream charStream(&fileReader);
        YamlParser::Stream yamlStream(&charStream);
        YamlParser::Decoder decoder(&yamlStream);

        YamlParser::Element* valuesObject = decoder.parse();
        if (valuesObject->getType() == YamlParser::ElementType::ObjectType) {
            auto rootObject = (std::map<std::string, YamlParser::Element*>*) valuesObject->getData();
            if (rootObject->find("regs") != rootObject->end()) {
                auto regsElement = rootObject->at("regs");
                if (regsElement->getType() == YamlParser::ElementType::ObjectType) {
                    auto regsElementObject = (std::map<std::string, YamlParser::Element*>*) regsElement->getData();
                    for (auto regsElementIt = regsElementObject->begin(); regsElementIt != regsElementObject->end(); regsElementIt++) {
                        if (regsElementIt->second->getType() == YamlParser::ElementType::PlainTextType) {
                            auto strValue = (std::string*) regsElementIt->second->getData();
                            (*this->regs)[regsElementIt->first] = *strValue;
                        }
                    }
                }
            }
        }

        std::cout << std::endl;
    }
}
