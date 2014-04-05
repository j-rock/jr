#include "CameraPositionMessage.h"

namespace jr
{

CameraPositionMessage::CameraPositionMessage(vec<float> position)
  : Message(Message::HIGH), worldPos(position)
{
}

CameraPositionMessage::~CameraPositionMessage()
{
}

void CameraPositionMessage::process()
{
  ((Renderer*)actor)->setCameraPos(worldPos);
}

}

