#ifndef GRAPHICS_RENDERER_H
#define GRAPHICS_RENDERER_H

#include <string>
#include <queue>
#include <vector>
#include <SFML/Graphics.hpp>
#include "GraphicsComponent.h"
#include "GraphicsComponentComparer.h"
#include "../Message/MessageHandler.h"
#include "../Utils/Math.h"
#include "../Utils/bbox.h"
#include "../Utils/vec.h"

namespace jr
{

using std::priority_queue;
using std::vector;
using Utils::vec;
using Utils::bbox;

class Renderer : public MessageHandler
{
	public:
		Renderer(int width, int height, std::string title);
		~Renderer();

    void render();
    bool isWindowOpen();
    void pollEvents();
    void updateBounds(bbox<float> newBounds);
    void addDrawMe(GraphicsComponent* gcomp);
    void setCameraPos(vec<float> worldPos);
    
  private:
    sf::RenderWindow* window;
    priority_queue<GraphicsComponent*,
                   vector<GraphicsComponent*>,
                   GraphicsComponentComparer> drawQueue;
    bbox<int> pixelBounds;
    int PIXELS_PER_METER;

    int pixelConvert(float real);
    int pixelConvertX(float realX);
    int pixelConvertY(float realY);
    sf::Vector2i pixel2Pixel(vec<float> worldPos);
    sf::Vector2i world2Pixel(vec<float> worldPos);
    sf::Vector2i extractPixelPos(GraphicsComponent* gcomp);
};

}
#endif
