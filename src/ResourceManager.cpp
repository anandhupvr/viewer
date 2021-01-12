#include "ResourceManager.h"




std::map<std::string, Texture2D>    ResourceManager::Textures;


Texture2D ResourceManager::LoadTexture(const char *file, std::string name)
{
    Textures[name] = loadTextureFromFile(file);
    return Textures[name];
}

Texture2D ResourceManager::GetTexture(std::string name)
{
    return Textures[name];
}

Texture2D ResourceManager::loadTextureFromFile(const char *file)
{
    // create texture object
    Texture2D texture;
    // if (alpha)
    // {
        // texture.Internal_Format = GL_RGBA;
        // texture.Image_Format = GL_RGBA;
    // }
    // load image
    cv::Mat img = cv::imread(file);
    cv::resize(img, img, cv::Size(640, 480));
    int width = img.cols;
    int height = img.rows;

    // now generate texture
    texture.Generate(width, height, img.data);
    return texture;
}