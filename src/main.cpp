#include "Engine/Core/Application.h"

#include <iostream>
#include <cstdlib>
#include <memory>
#include <string>
#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

Engine::Application *Engine::CreateApplication(Engine::ApplicationCommandLineArgs args)
{
    return new Engine::Application("OpenGL Tutorial", args);
}

int main(int argc, char **argv)
{
    Engine::Application *app = Engine::CreateApplication({argc, argv});

    app->Run();

    delete app;
}