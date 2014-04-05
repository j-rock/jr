#ifndef MESSAGES_UPDATEBOUNDSMESSAGE_H
#define MESSAGES_UPDATEBOUNDSMESSAGE_H

#include "../Message.h"
#include "../../Graphics/Renderer.h"
#include "../../Utils/bbox.h"

namespace jr
{

using Utils::bbox;

class UpdateBoundsMessage : public Message
{
	public:
		UpdateBoundsMessage(bbox<float> newBounds);
		~UpdateBoundsMessage();
    virtual void process();
    bbox<float> bounds;

};

}
#endif

