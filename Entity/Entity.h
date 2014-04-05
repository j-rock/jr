#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H

#include "../Graphics/GraphicsComponent.h"
#include "../Logic/LogicComponent.h"
#include "../Message/Message.h"
#include "../Message/MessageHandler.h"
#include "../Physics/PhysicsComponent.h"
#include "../Utils/bbox.h"

namespace jr
{

class Entity : public MessageHandler
{
	public:
    Entity(GraphicsComponent* g, LogicComponent* l, PhysicsComponent* p);
    virtual ~Entity();

    PhysicsComponent* getPhysicsComponent();
    Message* getCollideMessage();
    Message* getUncollideMessage();
    bbox<float> getBounds();
    void setSimHandler(MessageHandler* simulator);
    void setRendererHandler(MessageHandler* renderer);
    void setChildHandlers();
    void update();
    void sendPhysicsComponentUpdate();
    bool inWorldSpace();
    void takeMessage(Message* m);

    static void init();
    static void swap();


	private:
    GraphicsComponent* gcomp;
    LogicComponent* lcomp;
    PhysicsComponent* pcomp;
};

}
#endif
