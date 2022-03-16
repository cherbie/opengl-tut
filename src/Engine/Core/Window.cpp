#include "Engine/Core/Window.h"

#ifdef USE_GLFW
#include "Platform/Windows/WindowGLFW.h"
#endif

#include <stdexcept>

using namespace Engine;

/*static*/ std::unique_ptr<Window> Window::Create(const WindowProps &props)
{
#ifdef USE_GLFW
    return std::make_unique<WindowGLFW>(props);
#else
    std::runtime_error("Only GLFW supported at this stage");
#endif
}
