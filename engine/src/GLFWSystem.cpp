#include "kairo/GLFWSystem.hpp"
#include "GLFW/glfw3.h"

GLFWSystem::GLFWSystem(): isGLFWnitialized(false)
{   
    
}

GLFWSystem::~GLFWSystem()
{
    closeGLFW();
}

void GLFWSystem::closeGLFW()
{
      if(this->isGLFWnitialized)
    {
        glfwTerminate();
        this->isGLFWnitialized = false;
    }
}

bool GLFWSystem::getIsGLFWInitialized() const 
{
    return this->isGLFWnitialized;
}

void GLFWSystem::initGLFW()
{   
if(!isGLFWnitialized)
{
   if(glfwInit())
   {
    this->isGLFWnitialized =true;
   }
}

}

void GLFWSystem::PollEvents()
{
if(isGLFWnitialized){
    glfwPollEvents();}
}

