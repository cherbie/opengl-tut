#pragma once
#include "Core/Window.h"

#include <memory>

namespace Platform
{
    // GLFW window management implementation
    class WindowGLFW : public ::Core::Window
    {
    public:
        WindowGLFW(const ::Core::WindowProps &props);
        ~WindowGLFW();

        void OnUpdate() override;
        uint32_t GetWidth() const override;
        uint32_t GetHeight() const override;

        void *GetNativeWindow() const override;

    protected:
        class Impl;
        std::unique_ptr<Impl> m_impl;
    }; // class WindowGLFW
} // namespace Platform
