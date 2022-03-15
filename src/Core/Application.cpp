#include "Core/Application.h"

#ifdef USE_GLFW
#include "glad/glad.h"
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#endif
#include <functional>

#include <iostream>

namespace Core
{
    namespace
    {
        const char *vertexShaderSource = "#version 330 core\n"
                                         "layout (location = 0) in vec3 aPos;\n"
                                         "void main()\n"
                                         "{\n"
                                         "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                         "}\0";

        const char *fragmentShaderSource = "#version 330 core\n"
                                           "out vec4 FragColor;\n"
                                           "void main()\n"
                                           "{\n"
                                           "FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                                           "}\n";
#ifdef USE_GLFW
        void glfwWindowCloseCallback(GLFWwindow *window)
        {
            Application::Get().Close();
        }
#endif // USE_GLFW
    }

    Application *Application::s_Instance = nullptr;

    Application::Application(const std::string &name, ApplicationCommandLineArgs args)
    {
        s_Instance = this;
        m_window = Window::Create(WindowProps(name));
        m_running = true;

#ifdef USE_GLFW
        glfwSetWindowCloseCallback((GLFWwindow *)m_window->GetNativeWindow(), (GLFWwindowclosefun)glfwWindowCloseCallback);
#endif
    }

    Application::~Application()
    {
    }

    void Application::Close()
    {
        m_running = false;
    }

    void Application::Run()
    {
#ifdef USE_GLFW
        unsigned int VAO, VBO, EBO;
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);
        glGenVertexArrays(1, &VAO);

        // initialization code
        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

        // shaders
        int success;
        char infoLog[512];
        unsigned int const shaderProgram = glCreateProgram();
        unsigned int const vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
        unsigned int const fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);

        glCompileShader(vertexShader);
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            std::cerr << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
                      << infoLog
                      << std::endl;
        }

        glCompileShader(fragmentShader);
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
            std::cerr << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n"
                      << infoLog
                      << std::endl;
        }

        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);
        glLinkProgram(shaderProgram);
        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
            std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n"
                      << infoLog
                      << std::endl;
        }
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
        glUseProgram(shaderProgram);

        float const vertices[] = {
            0.5f, 0.5f, 0.0f,   // top right
            0.5f, -0.5f, 0.0f,  // bottom right
            -0.5f, -0.5f, 0.0f, // bottom left
            -0.5f, 0.5f, 0.0f   // top left
        };
        unsigned int const indices[] = {
            0, 1, 3, // first triangle
            1, 2, 3  // second triangle
        };

        // copy vertices into a buffer
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices,
                     GL_STATIC_DRAW);

        // set vertex attributes pointers
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float),
                              (void *)0);
        glEnableVertexAttribArray(0);

        while (m_running)
        {
            m_window->OnUpdate();

            // rendering
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            glUseProgram(shaderProgram);
            glBindVertexArray(VAO);
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void *)0);

            // swap buffers
            glfwSwapBuffers((GLFWwindow *)m_window->GetNativeWindow());
            glfwPollEvents();
        }
#endif // USE_GLFW
    }

    Window &Application::GetWindow()
    {
        return *m_window;
    }

    void Application::OnWindowClose()
    {
        std::cout << "closed window" << std::endl;
        m_running = false;
    }

    void Application::OnWindowResize()
    {
        std::cout << "resize" << std::endl;
    }
} // namespace Core
