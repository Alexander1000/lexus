#ifndef H_LEXUS_CONFIG
#define H_LEXUS_CONFIG

#include <map>
#include <string>
#include <list>

namespace Lexus
{
    class Rule
    {
    public:
        Rule(std::string* match);

        void setAction(std::string* action);

        std::string* getAction();

    private:
        std::string* action;

        std::string* match;
    };

    class Config
    {
    public:
        Config(const char*);

        std::list<std::string>* getStates();

        std::list<Rule*>* getRulesByState(std::string*);

    private:
        std::map<std::string, std::string>* regs;
        std::list<std::string>* states;

        std::map<std::string, std::list<Rule*>*>* stateRules;

        void scanConfigFile(const char*);
    };
}

#endif
