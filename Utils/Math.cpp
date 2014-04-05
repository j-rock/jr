#include "Math.h"

namespace jr
{

namespace Utils
{

  int max(int a, int b){
    return (a > b) ? a : b;
  }

  int min(int a, int b){
    return (a < b) ? a : b;
  }

  int roundf(float x){
    float addend = (x > 0.0) ? 0.5 : -0.5;
    return static_cast<int>(x + addend);
  }

  float cheapSqrt(float val){
    int tmp = *(int *)&val;
    tmp -= 1<<23;
    tmp = tmp >> 1;
    tmp += 1<<29;
    return *(float *)&tmp;
  }

  float rad2deg(float rad){
    //57.29... = 180 / pi
    return 57.2957795131 * rad;
  }

}

}
