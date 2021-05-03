#include <lexus.h>
#include <io-buffer.h>
#include <yaml-parser.h>
#include <string>
#include <map>
#include <iostream>
#include <list>

namespace Lexus
{
    Config::Config(const char* configFile)
    {
        this->scanConfigFile(configFile);
    }

    void Config::scanConfigFile(const char* configFile)
    {
        this->regs = new std::map<std::string, std::string>;
        this->states = new std::list<std::string>;
        this->stateRules = new std::map<std::string, std::list<Rule*>*>;

        IOBuffer::IOFileReader fileReader(configFile);
        IOBuffer::CharStream charStream(&fileReader);
        YamlParser::Stream yamlStream(&charStream);
        YamlParser::Decoder decoder(&yamlStream);

        YamlParser::Element* valuesObject = decoder.parse();

        if (valuesObject->getType() == YamlParser::ElementType::ObjectType) {
            auto rootObject = (std::map<std::string, YamlParser::Element*>*) valuesObject->getData();

            // parse regs
            if (rootObject->find("regs") != rootObject->end()) {
                auto regsElement = rootObject->at("regs");
                if (regsElement->getType() == YamlParser::ElementType::ObjectType) {
                    auto regsElementObject = (std::map<std::string, YamlParser::Element*>*) regsElement->getData();
                    for (auto & regsElementIt : *regsElementObject) {
                        if (regsElementIt.second->getType() == YamlParser::ElementType::PlainTextType) {
                            auto strValue = (std::string*) regsElementIt.second->getData();
                            (*this->regs)[regsElementIt.first] = *strValue;
                        }
                    }
                }
            }

            // parse rules
            if (rootObject->find("rules") != rootObject->end()) {
                auto rulesElement = rootObject->at("rules");
                if (rulesElement->getType() == YamlParser::ElementType::ObjectType) {
                    auto rulesElementObject = (std::map<std::string, YamlParser::Element*>*) rulesElement->getData();
                    for (auto & rulesElementIt : *rulesElementObject) {
                        // list states
                        this->states->push_back(rulesElementIt.first);

                        // initialize list rules for state
                        auto listRules = new std::list<Rule*>;

                        if (rulesElementIt.second->getType() == YamlParser::ElementType::ListType) {
                            // list rules
                            auto rulesStateElementList = (std::list<YamlParser::Element*>*) rulesElementIt.second->getData();

                            // iterate each rule
                            for (auto & rulesStateElementListIt : *rulesStateElementList) {
                                // parse rule element
                                if (rulesStateElementListIt->getType() == YamlParser::ElementType::ObjectType) {
                                    auto ruleObject = (std::map<std::string, YamlParser::Element*>*) rulesStateElementListIt->getData();
                                    Rule* rule = nullptr;

                                    if (ruleObject->find("match") != ruleObject->end()) {
                                        auto ruleMatchEl = ruleObject->at("match");
                                        if (ruleMatchEl->getType() == YamlParser::ElementType::PlainTextType) {
                                            auto match = (std::string*) ruleMatchEl->getData();
                                            rule = new Rule(match);
                                        }
                                    }

                                    if (rule != nullptr && ruleObject->find("action") != ruleObject->end()) {
                                        auto ruleActionEl = ruleObject->at("action");
                                        if (ruleActionEl->getType() == YamlParser::ElementType::PlainTextType) {
                                            auto action = (std::string*) ruleActionEl->getData();
                                            rule->setAction(action);
                                        }
                                    }

                                    if (rule != nullptr) {
                                        listRules->push_back(rule);
                                    }
                                }
                            }
                        }

                        // setup list rules for state
                        (*this->stateRules)[rulesElementIt.first] = listRules;
                    }
                }
            }
        }
    }

    std::list<std::string>* Config::getStates()
    {
        return this->states;
    }

    std::list<Rule*>* Config::getRulesByState(std::string* stateName)
    {
        if (this->stateRules->find(*stateName) == this->stateRules->end()) {
            return nullptr;
        }

        return this->stateRules->at(*stateName);
    }
}
