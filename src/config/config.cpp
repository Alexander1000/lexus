#include <lexus.h>
#include <io-buffer.h>
#include <yaml-parser.h>

namespace Lexus
{
    Config::Config(const char* configFile)
    {
        this->scanConfigFile(configFile);
    }

    void Config::scanConfigFile(const char* configFile)
    {
        IOBuffer::IOFileReader fileReader(configFile);
        IOBuffer::CharStream charStream(&fileReader);
        YamlParser::Stream yamlStream(&charStream);
        YamlParser::Decoder decoder(&yamlStream);

        YamlParser::Element* valuesObject = decoder.parse();
    }
}
