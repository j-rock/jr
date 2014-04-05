#ifndef LOGIC_LOGICCOMPONENT_H
#define LOGIC_LOGICCOMPONENT_H

#include <vector>
#include "LogicState.h"
#include "LogicData.h"
#include "../Entity/Component.h"
#include "../Message/Message.h"
#include "../Message/MessageHandler.h"
#include "../Utils/vec.h"

namespace jr
{

using std::vector;
using Utils::vec;

class LogicComponent : public MessageHandler, public Component
{
  friend class LogicState;

	public:
		LogicComponent();
		virtual ~LogicComponent();

    void setSimHandler(MessageHandler* simulator);
    void setHandlers(MessageHandler* pcomp, MessageHandler* gcomp);
    void update();
    void setPosition(vec<float> pos);
    void setVelocity(vec<float> vel);
    void setAngle(float angle);

    Message* getCollideMessage();
    Message* getUncollideMessage();

    static void init();
    static void swap();

  protected:
    int SIMULATOR_HANDLER;
    int PHYSICS_COMP_HANDLER;
    int GRAPHICS_COMP_HANDLER;

    void pop();
    void push(LogicState* state);
    void disableUpdate();

    virtual LogicState* getNewDefaultState() = 0;
    virtual LogicData* getNewDefaultData() = 0;

	private:
    bool doUpdate;
    vector<LogicState*> states[2];
    LogicData* data[2];

    LogicState* safePop();
    void copyOver();
    LogicState* getCurrentState();
    void processMessages();
    
    static int bufferIndex;
    static int current();
    static int next();


};

}
#endif
