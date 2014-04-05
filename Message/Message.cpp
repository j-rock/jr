#include "Message.h"

namespace jr
{

Message::Message(int prior)
{
  priority = prior;
}

Message::~Message()
{
}

const int Message::HIGH = 0;
const int Message::LOW = 7693;

}

