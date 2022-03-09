#include "Core/Window.h"

#define USE_GLFW

#ifdef USE_GLFW
    #include "Platform/WindowGLFW.h"
#endif

#include <stdexcept>

/*static*/ std::unique_ptr<Core::Window> Core::Window::Create(const Core::WindowProps& props) {
    #ifndef USE_GLFW
    std::runtime_error("Only GLFW supported at this stage");
    #endif
    return std::make_unique<Platform::WindowGLFW>(props);
}
