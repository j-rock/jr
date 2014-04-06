#ifndef PHYSICS_PHYSICSCOMPONENT_H
#define PHYSICS_PHYSICSCOMPONENT_H

#include <Box2D/Box2D.h>
#include "../Utils/bbox.h"
#include "../Utils/vec.h"

namespace jr
{

using Utils::bbox;
using Utils::vec;

class PhysicsComponent
{
	public:
    virtual ~PhysicsComponent();

    void leaveWorld();
    virtual void setPosition(vec<float> pos);
    virtual void setVelocity(vec<float> vel);
    virtual void setAngle(float angle);
    virtual bbox<float> getBounds();
    virtual vec<float> getPosition();
    virtual vec<float> getVelocity();
    virtual float getAngle();

    virtual void enterWorld(b2World* world) = 0;

  protected:
    b2Body* body;
};

}

#endif
