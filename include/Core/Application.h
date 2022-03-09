#pragma once
#include "Core/Window.h"

#include <memory>
#include <string>

int main(int argc, char **argv);

namespace Core {
    class Application { 
    public:
        Application(const std::string& name = "OpenGL Tutorial");
        virtual ~Application();

        void Close();
        
        Window& GetWindow();

        static Application& Get() { return *s_Instance; };
    private:
        void Run();
        void OnWindowClose();
        void OnWindowResize();

    private:
        std::unique_ptr<Window> m_window;
        bool m_running = false;

    private:
        static Application* s_Instance;
        friend int ::main(int argc, char** argv);
    }; // class Application
} // namespace Core

