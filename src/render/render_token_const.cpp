#include <lexus.h>
#include <iostream>

namespace Lexus
{
    void Render::renderTokenConst()
    {
        auto states = this->config->getStates();
        for (auto &stateIt : *states) {
            auto rules = this->config->getRulesByState(&stateIt);
            if (rules == nullptr) {
                continue;
            }
            for (auto &ruleIt : *rules) {
                if (ruleIt->getAction() != nullptr) {
                    std::cout << "Action: " << ruleIt->getAction()->c_str() << std::endl;
                }
            }
        }
    }
}
