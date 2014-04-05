#include "vec.h"

namespace jr
{
namespace Utils
{

template <class T>
vec<T>::vec(T _x, T _y)
{
  x = _x;
  y = _y;
}

template <class T>
vec<T>::vec()
{
}

template <class T>
vec<T>& vec<T>::operator=(const vec<T>& rhs)
{
  if(this == &rhs)
    return *this;
  x = rhs.x;
  y = rhs.y;
  return *this;
}

template class vec<float>;
template class vec<int>;

}
}
