#include <pangolin/gl/gl.h>


class VertexBuffer
{
private:
	unsigned int m_RenderingID;
public:
	VertexBuffer();
	~VertexBuffer();
	void Bind();
	void Unbind();
	void quad();
};