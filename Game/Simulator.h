#ifndef GAME_SIMULATOR_H
#define GAME_SIMULATOR_H

#include "../Entity/Entity.h"
#include "../Entity/EntityStore.h"
#include "../Message/MessageHandler.h"
#include "../Message/Messages/UpdateBoundsMessage.h"
#include "../Message/Messages/CameraPositionMessage.h"
#include "../Physics/PhysicsSimulator.h"


namespace jr
{

class Simulator : public MessageHandler
{
	public:
		Simulator(MessageHandler* renderer);
		virtual ~Simulator();
    
    void add(Entity* ent);
    void remove(Entity* ent);
    void update();

	private:
    PhysicsSimulator* physicsSim;
    EntityStore* entities;
    MessageHandler* rendererHandler;
    int RENDERER_HANDLER;

    void sendBoundsUpdate();
};

}
#endif
