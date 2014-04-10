#ifndef GRAPHICS_DRAWER_H
#define GRAPHICS_DRAWER_H

#include <SFML/Graphics.hpp>
#include "Renderer.h"
#include "../Utils/vec.h"

namespace jr
{

class Renderer;

using Utils::vec;

class Drawer
{
	public:
		Drawer(Renderer* r);
		~Drawer();

  void draw(sf::Drawable* img, int priority);
  vec<int> world2Pixel(float x, float y);
  vec<int> pixel2Pixel(int x, int y);


	private:
    Renderer* renderer;
};

}
#endif
