#include "Simulator.h"

namespace jr
{

Simulator::Simulator(MessageHandler* renderer)
{
  physicsSim = new PhysicsSimulator();
  entities = new EntityStore();
  rendererHandler = renderer;
  RENDERER_HANDLER = subscribe(renderer);
}

Simulator::~Simulator()
{
  delete physicsSim;
  delete entities;
}

void Simulator::update()
{
  entities->update();
  processMessages();
  sendBoundsUpdate();
  physicsSim->update();
  entities->sendPhysicsComponentUpdates();
}

void Simulator::add(Entity* ent)
{
  entities->add(ent);
  physicsSim->add(ent);
  ent->setSimHandler(getMessageHandler());
  ent->setRendererHandler(rendererHandler);
  ent->setChildHandlers();
}

void Simulator::remove(Entity* ent)
{
  entities->remove(ent);
  physicsSim->remove(ent);
  delete ent;
}

void Simulator::sendBoundsUpdate()
{
  Message* m1 = new UpdateBoundsMessage(physicsSim->getBounds());
  //TODO - Implement better camera positioning
  Message* m2 = new CameraPositionMessage(physicsSim->getBounds().getCenter());
  send(RENDERER_HANDLER, m1);
  send(RENDERER_HANDLER, m2);
}

}

