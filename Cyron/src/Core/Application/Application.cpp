#include "Core/Application/Application.hpp"
#include <iostream>
namespace Cyron {

    Application* Application::s_Instance = nullptr;

    Application::Application() {
        s_Instance = this;
    }
    Application::~Application() {

    }
    void Application::Run() {
        std::cout << "Hello" << std::endl;
    }

}