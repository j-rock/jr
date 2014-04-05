#ifndef PHYSICS_PHYSICSSIMULATOR_H
#define PHYSICS_PHYSICSSIMULATOR_H

#include <Box2D/Box2D.h>
#include "PhysicsComponent.h"
#include "ContactMessenger.h"
#include "../Entity/Entity.h"
#include "../Message/MessageHandler.h"
#include "../Utils/vec.h"

namespace jr
{

using Utils::vec;

class PhysicsSimulator : public MessageHandler
{
	public:
		PhysicsSimulator();
    PhysicsSimulator(vec<float> grav);
		virtual ~PhysicsSimulator();
    
    void add(Entity* ent);
    void remove(Entity* ent);
    void update();
    bbox<float> getBounds();

	private:
    b2World* world;
    ContactMessenger* contacter;
    bbox<float> bounds;

    void init(vec<float> grav);


};

}
#endif
