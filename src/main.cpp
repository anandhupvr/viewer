// #include <pangolin/pangolin.h>
// #include <shaders.h>
// #include <opencv2/imgproc/imgproc.hpp>
// #include <opencv2/highgui/highgui.hpp>
// #include "opencv2/opencv.hpp"
// #include "VertexBuffer.h"
// #include "VertexArray.h"
// #include <Renderer.h>

// int main( int /*argc*/, char** /*argv*/ )
// {


//     Renderer viewer(640, 480);
//     viewer.handlers();

//     std::shared_ptr<Shader> program;
//     program =  std::shared_ptr<Shader>(loadProgramFromFile("vertex_feedback.vert", "vertex_feedback.frag"));


//     float vertices1[] = {
//     0.5f, 0.5f, 0.0f, 
//     0.5f, -0.5f, 0.0f, 
//     -0.5f, -0.5f, 0.0f,
//     };



//     VertexBuffer vb(vertices1, sizeof(vertices1));
//     VertexArray va;
//     va.Bind();
//     va.addBuffer(3, sizeof(float) * 3);

//     Eigen::Vector3f red(1, 0, 0);
//     Eigen::Vector3f green(0, 1, 0);

//   while( !viewer.ShouldQuit() )
//   {
//     pangolin::OpenGlMatrix mvp = viewer.GetMvp();
//     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//     program->Bind();
//     program->setUniform(Uniform("MVP", mvp));
//     program->setUniform(Uniform("clr", red));

//     viewer.draw(va, vb);
//     va.Bind();
//     glDrawArrays(GL_TRIANGLES, 0, 3);
//     va.Unbind();
//     vb.Unbind();

//     program->Unbind();
//     pangolin::FinishFrame();


//   }
//   std::cout << "testing" << std::endl;
//   return 0;
// }
#include <pangolin/pangolin.h>
#include <shaders.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/opencv.hpp"


#include "Renderer.h"
#include "texture.h"
#include "VertexBuffer.h"

int main( int /*argc*/, char** /*argv*/ )
{

    Renderer game(640, 480);
    cv::Mat img = cv::imread("/home/developer/slam/src/muscle.jpg");
    cv::resize(img, img, cv::Size(640, 480));

    // cv::Mat img1 = cv::imread("/home/developer/slam/src/wall.jpg");
    // cv::resize(img1, img1, cv::Size(640, 480));


    std::shared_ptr<Shader> program;
    program =  std::shared_ptr<Shader>(loadProgramFromFile("vertex_feedback.vert", "vertex_feedback.frag"));

    int width = img.cols;
    int height = img.rows;


    unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);
    VertexBuffer vbo;
    vbo.quad();


    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    Texture2D texture;
    texture.Generate(width, height, img.data);
    // Texture2D texture1;
    // texture1.Generate(width, height, img1.data);

    glBindVertexArray(0);

    while( !game.ShouldQuit() )
    {
        // Clear screen and activate view to render into
        program->Bind();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        texture.Bind();
        glActiveTexture(GL_TEXTURE0);
        // texture1.Bind();
        // glActiveTexture(GL_TEXTURE1);
        pangolin::OpenGlMatrix mvp = game.GetMvp();

        program->setUniform(Uniform("MVP", mvp));
        glBindVertexArray(VAO);
        // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);


     glDrawArrays(GL_TRIANGLE_FAN, 0, 4);


     // glDisable(GL_TEXTURE_2D);

     program->Unbind();
        // Swap frames and Process Events
        pangolin::FinishFrame();
    }
    
    return 0;
}
