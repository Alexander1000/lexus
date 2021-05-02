#include <lexus.h>
#include <string>

namespace Lexus
{
    Command::Command(int argc, char **argv)
    {
        // defaults:
        this->is_help = false;
        this->is_version = false;

        // initialize parameters
        for (int i = 1; i < argc; i++) {
            std::string paramName(argv[i]);

            if (paramName == "-h" || paramName == "--help") {
                this->is_help = true;
                break;
            }

            if (paramName == "-v" || paramName == "--version") {
                this->is_version = true;
                break;
            }

            if (paramName == "-c" || paramName == "--config") {
                this->configFile = new std::string(argv[i+1]);
                i++;
                continue;
            }
        }
    }

    bool Command::isVersion() const
    {
        return this->is_version;
    }

    const char* Command::getVersionText()
    {
        return "lexus version: " LEXUS_VERSION "\n";
    }

    bool Command::isHelp() const
    {
        return this->is_help;
    }

    const char* Command::getHelpText()
    {
        return "Usage: lexus [OPTIONS]\n"
               "Common options:\n"
               "    -h, --help                 Show this message and exit.\n"
               "    -c, --config [file]        Config file.\n"
               "    -v, --version              Print version and exit.";
    }

    std::string* Command::getConfigFile()
    {
        return this->configFile;
    }
}
