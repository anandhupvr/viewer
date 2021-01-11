#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(){

	glGenBuffers(1, &m_RenderingID);
    // glBindBuffer(GL_ARRAY_BUFFER, m_RenderingID);
    // glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);	
}
VertexBuffer::~VertexBuffer(){

	glDeleteBuffers(1, &m_RenderingID);
}

void VertexBuffer::Bind(){
	glBindBuffer(GL_ARRAY_BUFFER, m_RenderingID);
}
void VertexBuffer::Unbind(){
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBuffer::quad()
{

    float vertices[] = {
        // positions          // colors           // texture coords
         0.5f,  0.5f, 0.0f, 1.0f, 1.0f, // top right
         0.5f, -0.5f, 0.0f, 1.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, // bottom left
        -0.5f,  0.5f, 0.0f, 0.0f, 1.0f  // top left 
    };


    glBindBuffer(GL_ARRAY_BUFFER, m_RenderingID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

}