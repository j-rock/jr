#ifndef PHYSICS_CONTACTMESSENGER_H
#define PHYSICS_CONTACTMESSENGER_H

#include <Box2D/Box2D.h>
#include "../Entity/Entity.h"
#include "../Message/Message.h"

namespace jr
{

class ContactMessenger : public b2ContactListener
{
	public:
    virtual void BeginContact(b2Contact* contact); 
    virtual void EndContact(b2Contact* contact);
};

}
#endif
