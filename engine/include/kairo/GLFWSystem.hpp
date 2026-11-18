#pragma once
#include <GLFW/glfw3.h> 

class GLFWSystem
{
    public:
        GLFWSystem();
        ~GLFWSystem();
        void initGLFW();
        GLFWSystem(const GLFWSystem&) = delete;
        GLFWSystem& operator=(const GLFWSystem&) = delete;
        bool getIsGLFWInitialized() const;
        void closeGLFW();
        void PollEvents();
        // void clearWindow(); // test purpose

    private:

    bool isGLFWnitialized;

};