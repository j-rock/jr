#ifndef UTILS_MESSAGEHANDLER_H
#define UTILS_MESSAGEHANDLER_H

#include <queue>
#include <vector>
#include "Message.h"
#include "MessageComparer.h"

namespace jr
{

using std::vector;
using std::priority_queue;

class MessageHandler
{
	public:
		virtual ~MessageHandler();

    int subscribe(MessageHandler* mh);
    void send(int mrIndex, Message* m);
    void broadcast(Message* m);
    virtual void processMessages();
    MessageHandler* getMessageHandler();

	protected:
    priority_queue<Message*, vector<Message*>, MessageComparer> messages;
    vector<MessageHandler*> subscribers;
};

}
#endif
