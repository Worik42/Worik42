#include "IUnknown.h"

class IComputeBox : public IUnknown_
{
public:
    virtual int getVBox(int measureSub) = 0;
    virtual void computeDirtyMeasuresBox() = 0;
};