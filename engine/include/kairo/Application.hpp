#pragma once
#include "kairo/GLFWSystem.hpp"
#include "kairo/Window.hpp"
#include <string>
class Application
{
    public:
    Application(std::string title);
    ~Application();
    const std::string getTitle() const;
    void Start();
    void Initialisation();
    bool getAppState() const {return this->is_running;} 
    void CloseApplication();
    private:
    bool is_running;
    std::string title; 
    GLFWSystem glfwSystem;
    Window window;

};