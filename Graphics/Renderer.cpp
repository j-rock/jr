#include "Renderer.h"

namespace jr
{

Renderer::Renderer(int width, int height, std::string title)
{
  window = new sf::RenderWindow(sf::VideoMode(width, height), title);
  PIXELS_PER_METER = 10;
}

Renderer::~Renderer()
{
  delete window;
}

Renderer::DrawObject::DrawObject(sf::Drawable* i, int p) : image(i), priority(p)
{
}

bool Renderer::DrawObject::operator<(const DrawObject& rhs) const
{
  return priority < rhs.priority;
}

bool Renderer::isWindowOpen()
{
  return window->isOpen();
}

void Renderer::pollEvents()
{
  sf::Event event;
  while(window->pollEvent(event)){
    if(event.type == sf::Event::Closed){
      window->close();
      return;
    }
    if(event.type == sf::Event::Resized)
    {
      sf::FloatRect visibleArea(0,0,event.size.width, event.size.height);
      window->setView(sf::View(visibleArea));
    }
  }
}


void Renderer::updateBounds(bbox<float> bounds)
{
  vec<float> world = bounds.getCenter();
  pixelBounds.minX = pixelConvert(bounds.minX);
  pixelBounds.maxX = pixelConvert(bounds.maxX);
  pixelBounds.minY = -pixelConvert(bounds.maxY);
  pixelBounds.maxY = -pixelConvert(bounds.minY);
  sf::Vector2f size(pixelBounds.maxX - pixelBounds.minX,
                    pixelBounds.maxY - pixelBounds.minY);
  sf::Vector2f center(pixelConvertX(world.x), pixelConvertY(world.y));
  sf::View newView(center, size);
  window->setView(newView);
}

int Renderer::pixelConvert(float real)
{
  return Utils::roundf(PIXELS_PER_METER * real);
}

int Renderer::pixelConvertX(float realX)
{
  return pixelConvert(realX) - pixelBounds.minX;
}

int Renderer::pixelConvertY(float realY)
{
  return -pixelConvert(realY) - pixelBounds.minY;
}

void Renderer::draw(sf::Drawable* img, int priority)
{
  DrawObject d(img, priority);
  drawQueue.push(d);
}

void Renderer::clearQueue()
{
  while(!drawQueue.empty())
    drawQueue.pop();
}

void Renderer::render()
{
   window->clear();
   while(!drawQueue.empty()){
     DrawObject d = drawQueue.top();
     drawQueue.pop();
     window->draw(*(d.image));
   }
   window->display();
}








}

