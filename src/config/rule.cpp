#include <lexus.h>

namespace Lexus
{
    Rule::Rule(std::string *match)
    {
        this->match = match;
        this->action = nullptr;
    }

    void Rule::setAction(std::string *action)
    {
        this->action = action;
    }

    std::string* Rule::getAction()
    {
        return this->action;
    }
}
