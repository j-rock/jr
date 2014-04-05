#include "RemoveEntityMessage.h"

namespace jr
{

RemoveEntityMessage::RemoveEntityMessage(Entity* ent)
  : Message(Message::LOW)
{
  this->ent = ent;
}

RemoveEntityMessage::~RemoveEntityMessage()
{
}

void RemoveEntityMessage::process()
{
  ((Simulator*)actor)->remove(ent);
}



}

