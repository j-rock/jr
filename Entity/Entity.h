#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H

#include <vector>
#include "../Graphics/GraphicsComponent.h"
#include "../Physics/PhysicsComponent.h"
#include "../Utils/bbox.h"

namespace jr
{

using std::vector;

//TODO - Clean up method ordering
class Entity
{
	public:
    Entity(GraphicsComponent* g, PhysicsComponent* p);
    virtual ~Entity();

    virtual void update() = 0;
    virtual void collideWith(Entity* other);
    virtual void endCollideWith(Entity* other);
    virtual bool isTouching();
    bbox<float> getBounds();
    PhysicsComponent* getPhysicsComponent();
    bool shouldDelete();
    bool isParent();
    vector<Entity*>& getChildren();
    void setDrawer(Drawer* d);
    bool wantsToSwitch();
    vector<Entity*>& getNewContext();


  protected:
    GraphicsComponent* gcomp;
    PhysicsComponent* pcomp;

    void scheduleDeletion(); 
    void spawn(Entity* child);
    void setPriority(int p);
    void switchContext(vector<Entity*> ents);

	private:
    bool deleteMe;
    int collideCount;
    vector<Entity*> children;
    vector<Entity*> newContext;
};

}
#endif
