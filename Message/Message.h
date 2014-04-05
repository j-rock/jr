#ifndef MESSAGE_MESSAGE_H
#define MESSAGE_MESSAGE_H

namespace jr
{

class Message
{
	public:
    Message(int prior);
		virtual ~Message();
    virtual void process() = 0;
    void* actor;
    void* sender;
    int priority;


    const static int HIGH;
    const static int LOW;
};

}
#endif
