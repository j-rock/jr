#ifndef UTILS_COMPARER_H
#define UTILS_COMPARER_H

namespace jr
{

class Comparer
{
	public:
		Comparer();
		virtual ~Comparer();
    virtual bool operator()(void* a, void* b) = 0;
};

}
#endif
