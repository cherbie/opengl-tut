#pragma once

#include <memory>
#include <string>
#include <functional>

namespace Core {
    struct WindowProps {
        std::string Title;
        uint32_t Width;
        uint32_t Height;

        WindowProps (const std::string& title = "OpenGL Tutorial",
                        uint32_t width = 800,
                        uint32_t height = 600)
            : Title(title), Width(width), Height(height)
        {
        }
    } // struct WindowProps

    // interface representing a desktop system based window
    class Window {
        public: 
            virtual ~Window() = default();

            virtual void OnUpdate();
            virtual uint32_t GetWidth() const = 0;
            virtual uint32_t GetHeight() const = 0;

            virtual void* GetNativeWindow() const = 0;
            
            static std::unique_ptr<Window> Create(const WindowProps& props = WindowProps());
        protected:
            class WindowCore;
            std::unique_ptr<WindowCore> m_core; 
    }; // class Window
} // namespace Core
