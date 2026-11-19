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
        return;

    glfwSwapInterval(1); // Enable VSync

    rendrer.setBackgroundColor();

    while (is_running)
    {
        // 1. Process window events
        glfwSystem.PollEvents();

        if (window.windowShouldClose())
            break;

        // 2. Retrieve actual framebuffer dimensions
        auto [width, height] = window.getFrameBufferSize();

        // 3. Skip rendering if framebuffer is unavailable
        if (width == 0 || height == 0)
            continue;

        // 4. Update the viewport every frame
        rendrer.setViewport(width, height);

        // 5. Clear the framebuffer
        rendrer.frameClear();

        rendrer.RenderTraingle();
       
        window.bufferSwap();
    }

    CloseApplication();
}