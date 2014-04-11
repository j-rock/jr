#include "Box.h"

namespace simple
{

Box::Box(float length, float x0, float y0)
  : jr::Entity(new RectShape(10*length, 10*length),
               new DynBox(length, x0, y0))
{
}

Box::~Box()
{
}

void Box::update()
{
  vec<float> pos = pcomp->getPosition();
  float ang = pcomp->getAngle();
  gcomp->setAngle(ang);
  gcomp->drawWorld(pos.x, pos.y);
}


}

