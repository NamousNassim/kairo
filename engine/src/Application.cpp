#include <iostream>
#include <kairo/Application.hpp>
#include <string>

Application::Application(std::string title) : is_running(false)
{   
    if(is_running)
    {
        std::cerr << "already working..." << std::endl;
        return;
    }

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


void Application::Start()
{     
    Initialisation();
        int a;
    while (is_running) {    
        std::cout << "Welcome " <<std::endl;
        std::cin >> a; 
        if (a == 0)
        {
            is_running = false;
        }
        
    }
}