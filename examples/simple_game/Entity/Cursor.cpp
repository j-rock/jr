#include "Cursor.h"

namespace simple
{

Cursor::Cursor(float x0, float y0)
  : jr::Entity(new NoGraphics(),
               new NoPhysics(x0, y0))
  
{
}

Cursor::~Cursor()
{
}

void Cursor::update()
{
}


}

