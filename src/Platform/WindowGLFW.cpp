#include "Platform/WindowGLFW.h"

#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdexcept>

namespace Platform
{
    namespace
    {
        void framebufferResizeCallback(GLFWwindow *window, int width, int height)
        {
            glViewport(0, 0, width, height);
        }
    }

    class WindowGLFW::impl
    {
    public:
        impl(const ::Core::WindowProps &props)
        {
            if (!glfwInit())
            {
                std::cerr << "Error initializating GLFW" << std::endl;
                exit(EXIT_FAILURE);
            }

            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

            m_window = glfwCreateWindow((int)props.Width, (int)props.Height, props.Title.c_str(),
                                        NULL, NULL);
            if (!m_window)
            {
                std::cerr << "Unable to create GLFW window" << std::endl;
                exit(EXIT_FAILURE);
            }

            glfwMakeContextCurrent(m_window);

            glViewport(0, 0, props.Width, props.Height);
            glfwSetFramebufferSizeCallback(m_window, framebufferResizeCallback);

            if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
            {
                std::cout << "Failed to initialize GLAD" << std::endl;
                throw std::runtime_error("Failed to initialize GLAD");
            }
        }
        virtual ~impl()
        {
            glfwDestroyWindow(m_window);
            glfwTerminate();
        }

    public:
        void OnUpdate()
        {
            if (glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
                glfwSetWindowShouldClose(m_window, true);
        }

        uint32_t GetWidth() const
        {
            int height, width;
            glfwGetFramebufferSize(m_window, &width, &height);
            return (uint32_t)width;
        }

        uint32_t GetHeight() const
        {
            int height, width;
            glfwGetFramebufferSize(m_window, &width, &height);
            return (uint32_t)height;
        }

        void *GetNativeWindow() const
        {
            return (void *)m_window;
        }

    private:
        GLFWwindow *m_window;
    }; // class WindowGLFW::impl

    //
    // --- WindowGLFW ---
    //
    WindowGLFW::WindowGLFW(const ::Core::WindowProps &props)
        : m_impl(std::make_unique<WindowGLFW::impl>(props))
    {
    }

    WindowGLFW::~WindowGLFW()
    {
    }

    void WindowGLFW::OnUpdate()
    {
        m_impl->OnUpdate();
    }

    uint32_t WindowGLFW::GetHeight() const
    {
        return m_impl->GetHeight();
    }

    uint32_t WindowGLFW::GetWidth() const
    {
        return m_impl->GetWidth();
    }

    void *WindowGLFW::GetNativeWindow() const
    {
        return m_impl->GetNativeWindow();
    }
} // namespace Platform
