#include "Core/Window.h"

#ifdef USE_GLFW
#include "Platform/WindowGLFW.h"
#endif

#include <stdexcept>

/*static*/ std::unique_ptr<Core::Window> Core::Window::Create(const Core::WindowProps &props)
{
#ifdef USE_GLFW
    return std::make_unique<Platform::WindowGLFW>(props);
#else
    std::runtime_error("Only GLFW supported at this stage");
#endif
}
