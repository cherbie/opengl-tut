#include "Platform/OpenGL/OpenGLContext.h"

namespace Engine
{
    //
    // OpenGLContext
    //
    OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
        : m_WindowHandle(windowHandle)
    {
    }
    
    void OpenGLContext::Init()
    {
        glfwMakeContextCurrent(m_WindowHandle);
        // todo
    }

    void OpenGLContext::SwapBuffers()
    {
       glfwSwapBuffers(m_WindowHandle);
    }
} // namespace Engine
