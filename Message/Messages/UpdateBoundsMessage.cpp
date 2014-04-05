#include "UpdateBoundsMessage.h"

namespace jr
{

UpdateBoundsMessage::UpdateBoundsMessage(bbox<float> newBounds)
  : Message(Message::HIGH), bounds(newBounds)
{
}

UpdateBoundsMessage::~UpdateBoundsMessage()
{
}

void UpdateBoundsMessage::process()
{
  ((Renderer*)actor)->updateBounds(bounds);
}


}

