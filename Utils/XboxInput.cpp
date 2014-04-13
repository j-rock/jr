#include "XboxInput.h"

namespace jr
{

XboxInput::XboxInput()
{
}

XboxInput::~XboxInput()
{
}

bool XboxInput::getButton(int controllerId, Button input)
{
  return sf::Joystick::isButtonPressed(controllerId, toSFButton(input));
}

float XboxInput::getAxis(int controllerId, Axis axis){
  return sf::Joystick::getAxisPosition(controllerId, toSFAxis(axis));
}

sf::Joystick::Axis XboxInput::toSFAxis(Axis axis)
{
  switch(axis){
    case LEFT_ANALOG_X:
      return sf::Joystick::X;
    case LEFT_ANALOG_Y:
      return sf::Joystick::Y;
    case RIGHT_ANALOG_X:
      return sf::Joystick::U;
    case RIGHT_ANALOG_Y:
      return sf::Joystick::V;
    case DPAD_X:
      return sf::Joystick::PovX;
    case DPAD_Y:
      return sf::Joystick::PovY;
    default:
      return sf::Joystick::R;
  }
}

int XboxInput::toSFButton(Button input)
{
  if(input >= 13)
    return -1;
  return input;
}

vector<int> XboxInput::getControllerIds()
{
  sf::Joystick::update();
  vector<int> ids;
  for(std::size_t i=0; i<sf::Joystick::Count; i++){
    if(sf::Joystick::isConnected(i)){
      if(sf::Joystick::getButtonCount(i) > 12){
        bool x    = sf::Joystick::hasAxis(i, sf::Joystick::X);
        bool y    = sf::Joystick::hasAxis(i, sf::Joystick::Y);
        bool u    = sf::Joystick::hasAxis(i, sf::Joystick::U);
        bool v    = sf::Joystick::hasAxis(i, sf::Joystick::V);
        bool povX = sf::Joystick::hasAxis(i, sf::Joystick::PovX);
        bool povY = sf::Joystick::hasAxis(i, sf::Joystick::PovY);
        if(x && y && u && v && povX && povY)
          ids.push_back(i);
      }
    }
  }
  return ids;
}

}

