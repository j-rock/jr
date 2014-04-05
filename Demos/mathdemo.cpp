#include <iostream>
#include <queue>
#include "../Utils.h"

using std::cout;
using std::endl;
using std::priority_queue;

int roundf(float x){
  int shift = 1 << 23;
  x += shift;
  return (int&)x & (shift - 1);
}

int main()
{

  for(float f=-10.0; f<10.0; f+=0.3){
    cout << "F=" << f << " => " << roundf(f) << endl;
  }

  return 0;
}

