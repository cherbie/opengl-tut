#include "Core/Application.h"

#include <iostream>
#include <cstdlib>
#include <memory>
#include <string>
#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

Core::Application *Core::CreateApplication(Core::ApplicationCommandLineArgs args)
{
    return new Core::Application("OpenGL Tutorial", args);
}

int main(int argc, char **argv)
{
    Core::Application *app = Core::CreateApplication({argc, argv});

    app->Run();

    delete app;
}