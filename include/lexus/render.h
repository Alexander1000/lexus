#ifndef H_LEXUS_RENDER
#define H_LEXUS_RENDER

#include <lexus/config.h>

namespace Lexus
{
    class Render
    {
    public:
        Render(Config *config);

    private:
        Config* config;
    };
}

#endif
