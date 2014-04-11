#ifndef GRAPHICS_RECTSHAPE_H
#define GRAPHICS_RECTSHAPE_H

#include <SFML/Graphics.hpp>
#include <jr/Graphics.h>

namespace simple
{

class RectShape : public jr::GraphicsComponent
{
	public:
		RectShape(float w, float h);
		~RectShape();

  protected:
    sf::Drawable* getDrawable();
    void changeImagePosition(int x, int y);

	private:
    sf::RectangleShape image;
};

}
#endif
