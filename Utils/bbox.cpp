#include "bbox.h"

namespace jr
{
namespace Utils
{

template <class T>
bbox<T>::bbox()
{
}

template <class T>
bbox<T>::bbox(T mnX, T mxX, T mnY, T mxY)
{
  minX = mnX;
  maxX = mxX;
  minY = mnY;
  maxY = mxY;
}

template <class T>
bool bbox<T>::overlaps(bbox<T>& other)
{
  if(other.minX >= maxX || other.maxX <= minX) return false;
  if(other.minY >= maxY || other.maxY <= minY) return false;
  return true;
}

template <class T>
bool bbox<T>::operator==(bbox<T>& other)
{
  return (minX == other.minX &&
          maxX == other.maxX &&
          minY == other.minY &&
          maxY == other.maxY);
}

template <class T>
bool bbox<T>::expandWith(bbox<T> other)
{
  bool changed = false;
  if(minX > other.minX){
    changed = true;
    minX = other.minX;
  }
  if(maxX < other.maxX){
    changed = true;
    maxX = other.maxX;
  }
  if(minY > other.minY){
    changed = true;
    minY = other.minY;
  }
  if(maxY < other.maxY){
    changed = true;
    maxY = other.maxY;
  }
  return changed;
}

template <class T>
vec<T> bbox<T>::getCenter()
{
  T x = (minX + maxX)/2;
  T y = (minY + maxY)/2;
  vec<T> center(x, y);
  return center;
}

template class bbox<int>;
template class bbox<float>;

}
}
