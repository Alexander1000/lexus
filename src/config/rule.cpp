#include <lexus.h>

namespace Lexus
{
    Rule::Rule(std::string *match)
    {
        this->match = match;
    }

    void Rule::setAction(std::string *action)
    {
        this->action = action;
    }
}
