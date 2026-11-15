#include "kairo/Window.hpp"

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
        // todo
    }
}
bool Window::getIsWindowCreated () const
{   
    return this->isWindowCreated;

}