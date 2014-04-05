#include "UpdateMessage.h"

namespace jr
{

UpdateMessage::UpdateMessage(vec<float> pos, vec<float> vel, float angle)
    : Message(Message::LOW)
{
  position = pos;
  velocity = vel;
  radianAngle = angle;
}

UpdateMessage::~UpdateMessage()
{
}

void UpdateMessage::process()
{
  Component* recipient = (Component*)actor;
  recipient->setPosition(position);
  recipient->setVelocity(velocity);
  recipient->setAngle(radianAngle);
}

}

