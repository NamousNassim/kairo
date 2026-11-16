#include "kairo/GLFWSystem.hpp"
#include "kairo/Window.hpp"
#include <iostream>
#include <kairo/Application.hpp>
#include <string>

Application::Application(std::string title) : is_running(false),title(title),window(720,1280,title)
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
        if(window.getIsWindowCreated()) this->is_running = true;
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
    
        int a;
    while (is_running)  {    
        std::cout << window.getIsWindowCreated() << std::endl;
        std::cout << this->getAppState() << std::endl;
        


        if (a == 0)
        {
            this->CloseApplication();
        }
        
    }
}