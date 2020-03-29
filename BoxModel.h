#include "IUnknown.h"
#include <string>
#include <sstream>

class BoxModel : public IUnknown_
{
public:
    virtual void setMeasures(int height, int width, int length, int measureSubwoofer, int lengthSub) = 0;
    virtual void printMeasuresBox() = 0;
};
