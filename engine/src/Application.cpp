#include <iostream>
#include <kairo/Application.hpp>
#include <string>

Application::Application(std::string title) : is_running(false)
{   
    this->title = title;
  
}

const std::string Application::getTitle()
{
    return this->title;
}

void Application::Initialisation()
{
    setiSRunning(true);
    // something else here
}

void Application::CloseApplication()
{
    this->is_running = false;
}

void Application::Start()
{     
    Initialisation();
        int a;
    while (is_running) {    
        std::cout << "Welcome " <<std::endl;
        std::cin >> a; 
        if (a == 0)
        {
            this->CloseApplication();
        }
        
    }
}