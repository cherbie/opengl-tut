#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Engine
{
    //
    // OpenGLVertexArray
    //
    OpenGLVertexArray::OpenGLVertexArray()
        : m_RendererID(), m_VertexBufferIndex(), m_VertexBuffer(),
          m_IndexBuffer()
    {
        glGenVertexArrays(1, &m_RendererID);
    }

    ~OpenGLVertexArray::OpenGLVertexArray()
    {
    }

    void OpenGLVertexArray::Bind() const
    {
        glBindVertexArray(m_RendererID);
    }

    void OpenGLVertexArray::Unbind() const
    {
        // todo
    }

    void AddVertexBuffer(const Ref<VertexBuffer> &vertexBuffer)
    {
        m_VertexBuffers.push_back(vertexBuffer);
    }

    void OpenGLVertexArray::SetIndexBuffer(const Ref<IndexBuffer> &indexBuffer)
    {
        std::move(m_IndexBuffer, indexBuffer);
        indexBuffer = nullptr;
    }
} // namespace Engine
