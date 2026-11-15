#include <kairo/engine.hpp>
#include <kairo/Application.hpp>

#include <iostream>

int main()
{
 Application  myApp = Application("KAIRO");

    std::cout << myApp.getTitle()  << std::endl;

    myApp.Start();
}
