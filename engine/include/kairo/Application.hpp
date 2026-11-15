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
    bool getAppState() const {return this->is_running;} 
    void CloseApplication();
    private:
    bool is_running;
    std::string title; 
};