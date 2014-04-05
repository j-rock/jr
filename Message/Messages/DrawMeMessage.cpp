#include "DrawMeMessage.h"

namespace jr
{

DrawMeMessage::DrawMeMessage(GraphicsComponent* gcomp)
  : Message(Message::LOW)
{
  this->gcomp = gcomp;
}

DrawMeMessage::~DrawMeMessage()
{
}

void DrawMeMessage::process()
{
  ((Renderer*)actor)->addDrawMe(gcomp);
}

}

