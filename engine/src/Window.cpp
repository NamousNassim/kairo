#include "kairo/Window.hpp"
#include "GLFW/glfw3.h"
#include <cstddef>

Window::Window(const unsigned int height , const unsigned width , std::string title) : isWindowCreated(false)
{
    this->height = height;
    this->width = width;
    this->title =title;
}



Window::~Window()
{
    if(this->isWindowCreated)
    {
    glfwDestroyWindow(this->window);
    this->window = nullptr;
    this->isWindowCreated = false;
    }
}
bool Window::getIsWindowCreated () const
{   
    return this->isWindowCreated;

}

bool Window::windowShouldClose() const
{   if(this->window != nullptr) 
    {
    return glfwWindowShouldClose(this->window);
    }
    else {
        return true;
    }
}

void Window::InitWindow()
{   if(!this->isWindowCreated)
    {
       this->window  = glfwCreateWindow(this->width,this->height,this->title.c_str(), nullptr, nullptr);
if (this->window) {
    this->isWindowCreated = true;
    glfwMakeContextCurrent(this->window);  
    }
    }
    
}

void Window::bufferSwap(){
    if(this->window != nullptr)
    glfwSwapBuffers(this->window);
}