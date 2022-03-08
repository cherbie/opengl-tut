#include "Core/Application.h"

namespace Core {
    Application* Application::s_Instance = nullptr;

    Application::Application(const std::string& name) {
        s_Instance = this;
        m_Window = Window::Create(WindowProps(name));
        m_Window->SetEventCallback(Application::OnEvent);
    }

    Application::~Application()
    {
    }

    void Application::Close() {
        m_running = false;
    }

    Application::Run() {
        while (m_running) {
            // do something
        }
    }


    Application::OnWindowResize() {
        // do something;
    }

} // namespace Core
