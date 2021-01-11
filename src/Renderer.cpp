#include "Renderer.h"


Renderer::Renderer(const float w, const float h):
window_width(w),
window_height(h)
{

	pangolin::CreateWindowAndBind("Main",window_width, window_height);
	glEnable(GL_DEPTH_TEST);

	// Define Projection and initial ModelView matrix
    s_cam = pangolin::OpenGlRenderState(pangolin::ProjectionMatrix(window_width, window_height, 420, 420, window_width / 2.0f, window_height / 2.0f, 0.1, 1000),
                                        pangolin::ModelViewLookAt(0, 0, -1, 0, 0, 1, pangolin::AxisNegY));
	// pangolin::Handler3D handler(s_cam);

	pangolin::View& d_cam = pangolin::CreateDisplay()
	     .SetBounds(0.0, 1.0, 0.0, 1.0, -window_width/window_height)
	     .SetHandler(new pangolin::Handler3D(s_cam));

}

bool Renderer::ShouldQuit()
{
	return pangolin::ShouldQuit();
}

pangolin::OpenGlMatrix Renderer::GetMvp()
{

    pangolin::OpenGlMatrix view = s_cam.GetModelViewMatrix();
    pangolin::OpenGlMatrix projection = s_cam.GetProjectionMatrix();
    pangolin::OpenGlMatrix model; //Entity->T_w_l;
    pangolin::OpenGlMatrix mvp =  projection * view;

    return mvp;


}

