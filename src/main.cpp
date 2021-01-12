#include <pangolin/pangolin.h>
#include <shaders.h>

#include "Renderer.h"
#include "VertexBuffer.h"
#include "ResourceManager.h"

int main( int /*argc*/, char** /*argv*/ )
{

    Renderer game(640, 480);


    std::shared_ptr<Shader> program;
    program =  std::shared_ptr<Shader>(loadProgramFromFile("vertex_feedback.vert", "vertex_feedback.frag"));

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

    ResourceManager::LoadTexture("/home/developer/slam/src/muscle.jpg", "test");

    glBindVertexArray(0);

    while( !game.ShouldQuit() )
    {
        // Clear screen and activate view to render into
        program->Bind();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        (ResourceManager::GetTexture("test")).Bind();
        // texture.Bind();
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
