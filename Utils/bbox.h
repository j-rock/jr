#ifndef UTILS_BBOX_H
#define UTILS_BBOX_H

#include "vec.h"

namespace jr
{
namespace Utils
{

template <typename T>
class bbox
{
	public:
    bbox<T>();
    bbox<T>(T mnX, T mxX, T mnY, T mxY);

    bool operator==(bbox<T>& other);
    bool overlaps(bbox<T>& other);
    bool expandWith(bbox<T> other);
    vec<T> getCenter();
    T minX, minY, maxX, maxY;
};

}
}
#endif
