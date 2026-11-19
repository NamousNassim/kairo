#pragma  once

#include "kairo/Window.hpp"
class Rendrer
{
    public:
    Rendrer(Window &window);
    ~Rendrer();
    void initRendrer();
    bool getIsRendrerActive () const;
    void frameClear();
    void setBackgroundColor();
    void setViewport(int width, int height);
    void RenderTraingle();
    private:
    bool isRendrerActive;
    Window &window;
};