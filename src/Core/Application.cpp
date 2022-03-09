#include "Core/Application.h"

#include "glad/glad.h"
#include <iostream>

namespace Core {
    Application* Application::s_Instance = nullptr;

    Application::Application(const std::string& name) {
        s_Instance = this;
        m_window = Window::Create(WindowProps(name));
    }

    Application::~Application()
    {
    }

    void Application::Close() {
        m_running = false;
    }

    void Application::Run() {
        while (m_running) {
            // do something
        }
    }

    Window& Application::GetWindow() {
        return *((Window*)m_window->GetNativeWindow());
    }

    void Application::OnWindowClose() {
        std::cout << "closed window" << std::endl;
    }

    void Application::OnWindowResize() {
        std::cout << "resize" << std::endl;
    }
} // namespace Core
