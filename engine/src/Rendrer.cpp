#include <glad/glad.h>
#include "kairo/Rendrer.hpp"
#include "kairo/Window.hpp"


Rendrer::Rendrer(Window &window) : window(window) , isRendrerActive(false)
{

}

Rendrer::~Rendrer() = default;

bool Rendrer::getIsRendrerActive() const
{
    return this->isRendrerActive;
}

void Rendrer::initRendrer()
{
    if(this->window.getIsWindowCreated())
    {
        if(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
       {
        this->isRendrerActive = true;
       }
    }
}

void Rendrer::setBackgroundColor()
{
        glClearColor(0.15f, 0.25f, 0.35f, 1.0f);

}

void Rendrer::frameClear()
{
            glClear(GL_COLOR_BUFFER_BIT);


}