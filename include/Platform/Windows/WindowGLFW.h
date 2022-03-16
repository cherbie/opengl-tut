#pragma once
#include "Engine/Core/Window.h"

#include <memory>

namespace Engine
{
    // GLFW window management implementation
    class WindowGLFW : public Window
    {
    public:
        WindowGLFW(const WindowProps &props);
        ~WindowGLFW();

        void OnUpdate() override;
        uint32_t GetWidth() const override;
        uint32_t GetHeight() const override;

        void *GetNativeWindow() const override;

    protected:
        class Impl;
        std::unique_ptr<Impl> m_impl;
    }; // class WindowGLFW
} // namespace Engine
