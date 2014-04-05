#ifndef MESSAGES_DRAWMEMESSAGE_H
#define MESSAGES_DRAWMEMESSAGE_H

#include "../Message.h"
#include "../../Graphics/GraphicsComponent.h"
#include "../../Graphics/Renderer.h"

namespace jr
{

class DrawMeMessage : public Message
{
	public:
		DrawMeMessage(GraphicsComponent* gcomp);
		virtual ~DrawMeMessage();
    virtual void process();
    GraphicsComponent* gcomp;
};

}
#endif

