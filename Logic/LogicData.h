#ifndef LOGIC_LOGICDATA_H
#define LOGIC_LOGICDATA_H

namespace jr
{

class LogicData
{
	public:
		virtual ~LogicData();
    virtual LogicData* clone() = 0;
};

}
#endif
