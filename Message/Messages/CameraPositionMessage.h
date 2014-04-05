#ifndef MESSAGES_CAMERAPOSITIONMESSAGE_H
#define MESSAGES_CAMERAPOSITIONMESSAGE_H

#include "../Message.h"
#include "../../Graphics/Renderer.h"
#include "../../Utils/vec.h"

namespace jr
{

using Utils::vec;

class CameraPositionMessage : public Message
{
	public:
		CameraPositionMessage(vec<float> position);
		~CameraPositionMessage();
    virtual void process();
    vec<float> worldPos;
};

}
#endif

