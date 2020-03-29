#include "BoxModel.h"
#include "IComputeBox.h"

class ComputeCloseBox : public BoxModel, IComputeBox
{
private:
    int height;
    int width;
    int length;
    int measureSubwoofer;
    int countLinks;
    int lengthSub;

    float vas;
    float fs;
    float qts;

    int volume;
    int resHeight;
    int resWidth;
    int resLength;

public:
    ComputeCloseBox();

    HRESULT_ QueryInterface_(IID_ &, void **);
    ULONG_ AddRef_();
    ULONG_ Release_();
    void setMeasures(int height,
                     int width,
                     int length,
                     int measureSubwoofer,
                     int lengthSub);
    void printMeasuresBox();
    int getVBox(int measureSub);
    void computeDirtyMeasuresBox();
};
