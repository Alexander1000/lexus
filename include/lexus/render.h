#ifndef H_LEXUS_RENDER
#define H_LEXUS_RENDER

#include <lexus/config.h>
#include <string>

namespace Lexus
{
    class Render
    {
    public:
        Render(Config* config, std::string* outputDir, std::string* headersDir);

        void run();

    private:
        Config* config;

        std::string* outputDir;
        std::string* headersDir;
    };
}

#endif
