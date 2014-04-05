#ifndef GRAPHICS_GRAPHICSCOMPONENT_H
#define GRAPHICS_GRAPHICSCOMPONENT_H

#include <SFML/Graphics.hpp>
#include "../Entity/Component.h"
#include "../Message/MessageHandler.h"
#include "../Utils/vec.h"

namespace jr
{

using Utils::vec;

class GraphicsComponent : public MessageHandler, public Component
{
	public:
		GraphicsComponent(int priority);
		virtual ~GraphicsComponent();

    void setRendererHandler(MessageHandler* renderer);
    void update();
    int getPriority();

    virtual bool usingPixelCoords() = 0;
    virtual vec<float> getPosition();
    void setPosition(vec<float> pos);
    void setVelocity(vec<float> vel);
    void setAngle(float radianAngle);
    virtual void setPixelPosition(sf::Vector2i pixelPos) = 0;
    virtual sf::Drawable* getDrawable() = 0;

  protected:
    int RENDERER_HANDLER;
    vec<float> position;
    vec<float> velocity;
    float angle;
  
  private:
    int priority;
};

}

#include "../Message/Messages/DrawMeMessage.h"

#endif
