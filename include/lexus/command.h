#ifndef H_LEXUS_COMMAND
#define H_LEXUS_COMMAND

#include <string>

namespace Lexus
{
    class Command
    {
    public:
        Command(int argc, char** argv);

        [[nodiscard]] bool isHelp() const;
        static const char* getHelpText();

        [[nodiscard]] bool isVersion() const;
        static const char* getVersionText();

        std::string* getConfigFile();

    private:
        bool is_help;
        bool is_version;

        std::string* configFile;
    };
}

#endif
