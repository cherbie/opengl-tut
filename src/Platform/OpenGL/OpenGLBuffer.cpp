#include "Platform/OpenGL/OpenGLBuffer.h"

#include "glad/glad.h"s

namespace Engine {
    OpenGLVertexBuffer::OpenGLVertexBuffer(uint32_t size)
        : m_Layout(size)
    {
        glGenBuffers(1, &m_RendererID);
    }

    OpenGLVertexBuffer::OpenGLVertexBuffer(float *vertices, uint32_t size)
        : m_layout(), m_RendererID()
    {
        glGenBuffers(1, &m_RendererID);
    }

    ~OpenGLVertexBuffer::OpenGLVertexBuffer()
    { 
    }

    void OpenGLVertexBuffer::Bind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
    }

    void OpenGLVertexBuffer::Unbind() const
    {
        // todo
    }

    void OpenGLVertexBuffer::SetData(const void* data, uint32_t size) 
    {
        // todo
    }


    //
    // OpenGLIndexBuffer
    //
    OpenGLIndexBuffer::OpenGLIndexBuffer(uint32_t* indices, uint32_t count)
        : m_RendererID(), m_Count(count)
    {
        glGenBuffers(1, &m_RendererID);
    }

    ~OpenGLIndexBuffer::OpenGLIndexBuffer()
    {
    }

    void OpenGLIndexBuffer::Bind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
    }

    void OpenGLIndexBuffer::Unbind() const
    {
        // todo
    }
}
