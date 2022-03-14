#pragma once
#include "Core/Window.h"

#include <memory>
#include <string>
#include <cassert>

int main(int argc, char **argv);

namespace Core
{
    struct ApplicationCommandLineArgs
    {
        int Count = 0;
        char **Args = nullptr;

        const char *operator[](int index) const
        {
            assert(index < Count);
            return Args[index];
        }
    };

    class Application
    {
    public:
        Application(const std::string &name,
                    ApplicationCommandLineArgs args = ApplicationCommandLineArgs());
        virtual ~Application();

        void Close();

        Window &GetWindow();

        static Application &Get() { return *s_Instance; };

    private:
        void Run();
        void OnWindowClose();
        void OnWindowResize();

    private:
        std::unique_ptr<Window> m_window;
        bool m_running = false;

    private:
        static Application *s_Instance;
        friend int ::main(int argc, char **argv);
    }; // class Application

    extern Application *CreateApplication(ApplicationCommandLineArgs args);
} // namespace Core
