#include "MessageHandler.h"

namespace jr
{

MessageHandler::~MessageHandler()
{
  while(!messages.empty()){
    delete messages.top();
    messages.pop();
  }
}

int MessageHandler::subscribe(MessageHandler* mr)
{
  subscribers.push_back(mr);
  return subscribers.size()-1;
}

void MessageHandler::send(int mrIndex, Message* m)
{
  m->sender = (void*)this;
  MessageHandler* recipient = subscribers[mrIndex];
  recipient->messages.push(m);
}

void MessageHandler::broadcast(Message* m)
{
  for(std::size_t i=0; i<subscribers.size(); i++)
    send(i, m);
}

void MessageHandler::processMessages()
{
  while(!messages.empty()){
    Message* m = messages.top();
    messages.pop();
    m->actor = this;
    m->process();
    delete m;
  }
}

MessageHandler* MessageHandler::getMessageHandler()
{
  return this;
}

}

