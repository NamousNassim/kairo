#pragma once
#include "kairo/GLFWSystem.hpp"
#include <string>
#include <utility>
class Window
{
    public:
    Window(const unsigned int height , const unsigned width , std::string title);
    ~Window();
    void InitWindow();
    void CloseWindow();
    bool getIsWindowCreated ()const;
    bool windowShouldClose() const;
    void bufferSwap();
    std::pair<int, int> getFrameBufferSize() const;
    private:
    std::string title;
    unsigned int height;
    unsigned int width;
    bool isWindowCreated;
    GLFWwindow* window = nullptr;

};
