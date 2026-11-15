#pragma once
#include <string>
class Application
{
    public:
    Application(std::string title);
    const std::string getTitle();
    void setiSRunning(bool isRunning){ this->is_running = isRunning; }
    void Start();
    void Initialisation();
    private:
    bool is_running;
    std::string title; 
};