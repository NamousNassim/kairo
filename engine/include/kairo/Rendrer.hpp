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
    private:
    bool isRendrerActive;
    Window &window;
};