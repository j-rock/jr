#ifndef MESSAGES_REMOVEENTITYMESSAGE_H
#define MESSAGES_REMOVEENTITYMESSAGE_H

#include "../Message.h"
#include "../../Game/Simulator.h"
#include "../../Entity/Entity.h"

namespace jr
{

class RemoveEntityMessage : public Message
{
	public:
		RemoveEntityMessage(Entity* ent);
		virtual ~RemoveEntityMessage();
    virtual void process();
    Entity* ent;
};

}
#endif
