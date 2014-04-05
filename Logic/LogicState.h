#ifndef LOGIC_LOGICSTATE_H
#define LOGIC_LOGICSTATE_H

#include "LogicData.h"
#include "../Message/Message.h"
#include "../Utils/vec.h"

namespace jr
{

using Utils::vec;

class LogicComponent;
class LogicState
{
	public:
		virtual ~LogicState();
    virtual void update(LogicComponent* lcomp) = 0;
    virtual void setData(LogicData* data) = 0;
    virtual void setPosition(vec<float> pos) = 0;
    virtual void setVelocity(vec<float> vel) = 0;
    virtual void setAngle(float angle) = 0;
    virtual Message* getCollideMessage() = 0;
    virtual Message* getUncollideMessage() = 0;

  protected:
    void pop(LogicComponent* lcomp);
    void push(LogicComponent* lcomp, LogicState* state);
};

}

#include "LogicComponent.h"
#endif
