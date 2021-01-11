#include "VertexArray.h"
#include <pangolin/pangolin.h>


VertexArray::VertexArray()
{
	glGenVertexArrays(1, &m_RenderingID);

}
VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &m_RenderingID);
}

void VertexArray::addBuffer(int count, float size)
{
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, count, GL_FLOAT, GL_FALSE, size, (void*)0);

}

void VertexArray::Bind()
{
	glBindVertexArray(m_RenderingID);
}
void VertexArray::Unbind()
{
	glBindVertexArray(0);
}
