#ifndef PHYSICS_PHYSICSCOMPONENT_H
#define PHYSICS_PHYSICSCOMPONENT_H

#include <Box2D/Box2D.h>
#include "../Entity/Component.h"
#include "../Message/MessageHandler.h"
#include "../Message/Messages/UpdateMessage.h"
#include "../Utils/bbox.h"
#include "../Utils/vec.h"

namespace jr
{

using Utils::bbox;
using Utils::vec;

class PhysicsComponent : public MessageHandler, public Component
{
	public:
    virtual ~PhysicsComponent();

    void setHandlers(MessageHandler* gcomp, MessageHandler* lcomp);
    void leaveWorld();
    void update();
    void sendUpdates();
    void setUserData(void* data);
    void setPosition(vec<float> pos);
    void setVelocity(vec<float> vel);
    void setAngle(float angle);
    bbox<float> getBounds();

    virtual void enterWorld(b2World* world) = 0;

  protected:
    b2Body* body;

  private:
    int GRAPHICS_HANDLER;
    int LOGIC_HANDLER;

    virtual vec<float> getPosition();
    virtual vec<float> getVelocity();
    virtual float getAngle();

};

}

#endif
