#ifndef H_LEXUS_CONFIG
#define H_LEXUS_CONFIG

namespace Lexus
{
    class Config
    {
    public:
        Config(const char*);

    private:
        void scanConfigFile(const char*);
    };
}

#endif
