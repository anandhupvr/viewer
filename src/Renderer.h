#include <pangolin/pangolin.h>


class Renderer
{

private:
	const float window_width;
	const float window_height;
	pangolin::OpenGlRenderState s_cam;
	pangolin::View d_cam;

public:
	Renderer(const float w, const float h);
	bool ShouldQuit();
	pangolin::OpenGlMatrix GetMvp();

};