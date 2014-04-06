#ifndef GRAPHICS_RENDERER_H
#define GRAPHICS_RENDERER_H

#include <string>
#include <queue>
#include <vector>
#include <SFML/Graphics.hpp>
#include "../Utils/Math.h"
#include "../Utils/bbox.h"
#include "../Utils/vec.h"

namespace jr
{

using std::priority_queue;
using std::vector;
using Utils::vec;
using Utils::bbox;

class Renderer
{
	public:
		Renderer(int width, int height, std::string title);
		~Renderer();

    void render();
    bool isWindowOpen();
    void pollEvents();
    void updateBounds(bbox<float> newBounds);
    
  private:
    sf::RenderWindow* window;
    //TODO - implement priority queue properly
    //TODO - implement draw function
    bbox<int> pixelBounds;
    int PIXELS_PER_METER;

    int pixelConvert(float real);
    int pixelConvertX(float realX);
    int pixelConvertY(float realY);
};

}
#endif
