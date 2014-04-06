#ifndef GRAPHICS_GRAPHICSCOMPONENT_H
#define GRAPHICS_GRAPHICSCOMPONENT_H

#include <SFML/Graphics.hpp>

namespace jr
{

class GraphicsComponent
{
	public:
		GraphicsComponent();
		virtual ~GraphicsComponent();

    virtual void draw() = 0;

};

}


#endif
