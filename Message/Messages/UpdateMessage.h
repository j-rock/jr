#ifndef MESSAGES_UPDATEMESSAGE_H
#define MESSAGES_UPDATEMESSAGE_H

#include "../Message.h"
#include "../../Entity/Component.h"
#include "../../Utils/vec.h"

namespace jr
{

using Utils::vec;

class UpdateMessage : public Message
{
	public:
		UpdateMessage(vec<float> pos, vec<float> vel, float angle);
		virtual ~UpdateMessage();
    virtual void process();
    vec<float> position;
    vec<float> velocity;
    float radianAngle;
};

}
#endif

