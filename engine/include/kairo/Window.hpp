#pragma once
#include <string>
class Window
{
    public:
    Window(const unsigned int height , const unsigned width , std::string title,bool isAppRunning);
    ~Window();
    void InitWindowt();
    void CloseWindow();

    private:
    std::string title;
    unsigned int height;
    unsigned int width;
    bool isCreated;

};