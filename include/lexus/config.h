#ifndef H_LEXUS_CONFIG
#define H_LEXUS_CONFIG

namespace Lexus
{
    class Config
    {
    public:
        Config(int argc, char** argv);

        bool isHelp();
        static const char* getHelpText();

        bool isVersion();
        static const char* getVersionText();

    private:
        bool is_help;
        bool is_version;
    };
}

#endif
