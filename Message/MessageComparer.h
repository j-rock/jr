#ifndef MESSAGE_MESSAGECOMPARER_H
#define MESSAGE_MESSAGECOMPARER_H

#include "Message.h"
#include "../Utils/Comparer.h"

namespace jr
{

class MessageComparer : public Comparer
{
	public:
		MessageComparer();
		~MessageComparer();
    virtual bool operator()(void* a, void* b);
};

}
#endif
