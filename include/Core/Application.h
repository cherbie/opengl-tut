#pragma once

#include <memory>
#include <string>

#include "Core/Window.h"

namespace Core {
    class Application { 
    public:
        Application(std::string& name = "OpenGL Tutorial");
        virtual ~Application();

        void Close();
        
        Window& GetWindow();

        static Application& Get() { return *s_Instance; };
    private:
        void Run();
        bool OnWindowClose(WindowCloseEvent& e);
        bool OnWindowResize(WindowResizeEvent& e);

    private:
        std::unique_ptr<Window> m_window;
        bool m_running = false;

    private:
        static Application* s_Instance;
        friend int ::main(int argc, char** argv);
    }; // class Application
} // namespace Core

