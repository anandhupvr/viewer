#include "texture.h"
#include <map>
#include <string>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/opencv.hpp"


class ResourceManager
{
private:
public:
    
    static std::map<std::string, Texture2D> Textures;
    static Texture2D LoadTexture(const char *file, std::string name);
    static Texture2D GetTexture(std::string name);
    ResourceManager(){ }
    static Texture2D loadTextureFromFile(const char *file);
};