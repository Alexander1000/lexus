#include <lexus.h>
#include <string>

namespace Lexus
{
    Render::Render(Config* config, std::string* outputDir, std::string* headersDir)
    {
        this->config = config;
        this->outputDir = outputDir;
        this->headersDir = headersDir;
    }

    void Render::run()
    {
        this->renderTokenConst();
    }
}
