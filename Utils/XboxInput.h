#ifndef UTILS_XBOXINPUT_H
#define UTILS_XBOXINPUT_H

#include <vector>
#include <SFML/Window.hpp>

namespace jr
{

using std::vector;

class XboxInput
{
	public:

    enum Axis {
      LEFT_ANALOG_X, LEFT_ANALOG_Y,
      RIGHT_ANALOG_X, RIGHT_ANALOG_Y,
      DPAD_X, DPAD_Y
    };

    enum Button {
      A, B, X, Y,
      LB, RB, L3, R3,
      BACK, START, XBOX_BUTTON,
      LT, RT
    };

    static bool getButton(int controllerId, Button input);
    static float getAxis(int controllerId, Axis input);
    static vector<int> getControllerIds();

  private:
    static int toSFButton(Button input);
    static sf::Joystick::Axis toSFAxis(Axis input);
		XboxInput();
		~XboxInput();

};

}
#endif
