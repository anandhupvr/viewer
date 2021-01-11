class VertexArray
{
private:
	unsigned int m_RenderingID;
public:
	VertexArray();
	~VertexArray();
	void addBuffer(int count, float size);
	void Bind();
	void Unbind();
};