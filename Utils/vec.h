#ifndef UTILS_VEC_H
#define UTILS_VEC_H

namespace jr
{
namespace Utils
{

template <typename T>
class vec
{
	public:
    vec<T>(T x, T y);
    vec<T>();
    vec<T>& operator=(const vec<T>& rhs);
    T x;
    T y;
};

}
}
#endif
