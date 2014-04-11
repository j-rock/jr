#ifndef GRAPHICS_GRAPHICSCOMPONENT_H
#define GRAPHICS_GRAPHICSCOMPONENT_H

#include <SFML/Graphics.hpp>
#include "Drawer.h"

namespace jr
{

class GraphicsComponent
{
	public:
		GraphicsComponent();
		virtual ~GraphicsComponent();

    virtual void drawWorld(float x, float y);
    virtual void drawPixel(int x, int y);
    void setDrawer(Drawer* d);
    void setPriority(int p);

  protected:
    Drawer* drawer;
    int priority;

    virtual void changeImagePosition(int x, int y) = 0;
    virtual sf::Drawable* getDrawable() = 0;

  private:
    void doDraw(int x, int y);

};

}


#endif
