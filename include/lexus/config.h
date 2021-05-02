#ifndef H_LEXUS_CONFIG
#define H_LEXUS_CONFIG

#include <map>
#include <string>
#include <list>

namespace Lexus
{
    class Config
    {
    public:
        Config(const char*);

    private:
        std::map<std::string, std::string>* regs;
        std::list<std::string>* states;

        void scanConfigFile(const char*);
    };
}

#endif
