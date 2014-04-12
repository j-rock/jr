#include "Game.h"

#define MS_PER_UPDATE 16

namespace jr
{

Game::Game(vector<Entity*>& ents)
{
  renderer = new Renderer(900, 550, "Game");
  entities = new EntityStore(new Drawer(renderer));
  physicsSim = new PhysicsSimulator();

  for(std::size_t i=0; i<ents.size(); i++)
    add(ents[i]);
}

Game::~Game()
{
  delete physicsSim;
  delete entities;
  delete renderer;
}

void Game::switchContext(vector<Entity*>& ents)
{
  delete physicsSim;
  delete entities;

  entities = new EntityStore(new Drawer(renderer));
  physicsSim = new PhysicsSimulator();

  for(std::size_t i=0; i<ents.size(); i++)
    add(ents[i]);

  renderer->clearQueue();
}

void Game::add(Entity* ent)
{
  entities->add(ent);
  physicsSim->add(ent);
}

void Game::remove(Entity* ent)
{
  entities->remove(ent);
  physicsSim->remove(ent);
  delete ent;
}

void Game::addChildren(vector<Entity*>& children)
{
  for(std::size_t i=0; i<children.size(); i++)
    add(children[i]);
  children.clear();
}

void Game::addParentsChildren(vector<Entity*>& parents)
{
  for(std::size_t i=0; i<parents.size(); i++)
    addChildren(parents[i]->getChildren());
  parents.clear();
}

void Game::removeDeletes(vector<Entity*>& deletes)
{
  for(std::size_t i=0; i<deletes.size(); i++)
    remove(deletes[i]);
  deletes.clear();
}

void Game::update()
{
  entities->update();
  addParentsChildren(entities->getParents());
  removeDeletes(entities->deletes());
  if(entities->wantsToSwitchContext()){
    switchContext(entities->getNewContext());
    return;
  }
  physicsSim->update();
  //TODO - look into refreshing bounds on every update (if not too costly)
  renderer->updateBounds(physicsSim->getBounds());
  renderer->render();
}


void Game::play()
{
  sf::Clock clock;
  while (renderer->isWindowOpen()){
    update();
    renderer->pollEvents();
    sleep(clock.restart());
  }
}

void Game::sleep(sf::Time elapsed)
{
  //TODO - Reconsider choice of sleep function
  sf::Time maxSleep = sf::milliseconds(16); //for 60 fps
  sf::Time sleepTime;
  if(maxSleep > elapsed)
    sleepTime = maxSleep - elapsed;
  else
    sleepTime = sf::Time::Zero;
  sf::sleep(sleepTime);
}

}
