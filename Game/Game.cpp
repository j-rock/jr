#include "Game.h"

#define MS_PER_UPDATE 16

namespace jr
{

Game::Game(vector<Entity*>& ents)
{
  //maybe use Renderer::Init(900, 550, "Game");
  renderer = new Renderer(900, 550, "Game");
  entities = new EntityStore();
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
  //TODO - must inform graphics of new bounds
  physicsSim->update();
}


void Game::play()
{
  sf::Clock clock;
  while (renderer->isWindowOpen()){
    simulator->update();
    sleep(clock.restart());
    renderer->render();
    renderer->pollEvents();
  }
}

void Game::sleep(sf::Time elapsed)
{
  //Reconsider choice of sleep function
  sf::Time maxSleep = sf::milliseconds(16); //for 60 fps
  sf::Time sleepTime;
  if(maxSleep > elapsed)
    sleepTime = maxSleep - elapsed;
  else
    sleepTime = sf::Time::Zero;
  sf::sleep(sleepTime);
}

}
