#include "kairo/GLFWSystem.hpp"
#include "kairo/Rendrer.hpp"
#include "kairo/Window.hpp"
#include <iostream>
#include <kairo/Application.hpp>
#include <string>


Application::Application(std::string title) : is_running(false),title(title),window(720,1280,title) , rendrer(window)
{   
  
    
}

Application::~Application()
{
    CloseApplication();
}

const std::string Application::getTitle() const
{
    return this->title;
}


void Application::Initialisation()
{
    if (!is_running)
    {
    
    glfwSystem.initGLFW();
    
    if(glfwSystem.getIsGLFWInitialized())
    {   
        window.InitWindow();
        if(window.getIsWindowCreated()) 
        {
            rendrer.initRendrer();
            if(rendrer.getIsRendrerActive())
            {this->is_running = true;}
        }
        
    }
}
}
void Application::CloseApplication()
{
    if(this->is_running)
    {
    this->is_running = false;
    }
}

void Application::Start()
{
    Initialisation();
    if (!is_running || !rendrer.getIsRendrerActive())
    {
        return;
    }

    
    glfwSwapInterval(1);

    rendrer.setBackgroundColor();

    while (is_running)
    {
        glfwSystem.PollEvents();

        if (window.windowShouldClose())
        {
            CloseApplication();
            break;
        }
        rendrer.frameClear();

        window.bufferSwap();
    }

    CloseApplication();
}