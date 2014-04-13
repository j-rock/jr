#ifndef PHYSICS_COLLIDELISTENER_H
#define PHYSICS_COLLIDELISTENER_H

#include <Box2D/Box2D.h>
#include "../Entity/Entity.h"

namespace jr
{

class CollideListener : public b2ContactListener
{
	public:
    void BeginContact(b2Contact* contact);
    void EndContact(b2Contact* contact);
};

}
#endif
