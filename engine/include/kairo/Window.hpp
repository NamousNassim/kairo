#pragma once
#include <string>
class Window
{
    public:
    Window(const unsigned int height , const unsigned width , std::string title);
    ~Window();
    void InitWindowt();
    void CloseWindow();
    bool getIsWindowCreated ()const;

    private:
    std::string title;
    unsigned int height;
    unsigned int width;
    bool isWindowCreated;

};