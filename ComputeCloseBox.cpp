#include "ComputeCloseBox.h"
#include "math.h"
#include <iostream>
using namespace std;

ComputeCloseBox::ComputeCloseBox()
{
    printf("ConstructorOnCloseBox\n");
    this->countLinks = 0;
};

void ComputeCloseBox::setMeasures(int height, int width, int length, int measureSubwoofer, int lengthSub)
{
    this->height = height;
    this->width = width;
    this->length = length;
    this->measureSubwoofer = measureSubwoofer;
    this->lengthSub = lengthSub;
}
void ComputeCloseBox::printMeasuresBox()
{
    cout << "Volume\t" << volume << '\n';
    cout << "Height\t" << resHeight << '\n';
    cout << "Width\t" << resWidth << '\n';
    cout << "Length\t" << resLength << '\n';
}
int ComputeCloseBox::getVBox(int measureSub)
{
    switch (measureSub)
    {
    case 8:
        return 12;
        break;
    case 10:
        return 20;
        break;
    case 12:
        return 32;
        break;
    case 15:
        return 48;
        break;
    case 18:
        return 80;
        break;
    default:
        break;
    }
}
void ComputeCloseBox::computeDirtyMeasuresBox()
{
    double vBox = getVBox(measureSubwoofer) * 1000000;
    float diaSub = measureSubwoofer * 2.54;
    double hlw = cbrt(vBox);
    float maxVBox = width * height * length;
    if (maxVBox < vBox)
    {
        printf("Error measure");
    }
    else if (maxVBox == vBox)
    {
        resHeight = height;
        resLength = length;
        resWidth = width;
        return;
    }
    else if (maxVBox > vBox)
    {
        float width_ = hlw;
        float height_ = hlw;
        float length_ = hlw;
        if (height_ > height)
        {

            height_ = height;
            maxVBox = height_ * width_ * length_;
            while (maxVBox < (vBox - 500000) || maxVBox > (vBox + 500000))
            {
                width_ += 1;
                length_ += 1;
                maxVBox = height_ * width_ * length_;
            }
        }
        if (length_ > length)
        {
            length_ = length;
            maxVBox = height_ * width_ * length_;
            while (maxVBox < (vBox - 500000) || maxVBox > (vBox + 500000))
            {
                width_ += 1;
                maxVBox = height_ * width_ * length_;
            }
        }

        this->resHeight = (int)height_;
        this->resLength = (int)length_;
        this->resWidth = (int)width_;
        this->volume = (int)(height_ * length_ * width_);
    }
}

HRESULT_ ComputeCloseBox::QueryInterface_(IID_ &iid, void **ppv)
{
    printf("QueryInterfaceCloseBox:%d\n", iid);
    if (iid == 0)
    {
        *ppv = (void *)(IUnknown_ *)(IComputeBox *)this;
        this->AddRef_();
        return 0;
    }
    else if (iid == 1)
    {
        *ppv = (void *)(BoxModel *)this;
        this->AddRef_();
        return 0;
    }
    else if (iid == 2)
    {
        *ppv = (void *)(IComputeBox *)this;
        this->AddRef_();
        return 0;
    }
    else
    {
        *ppv = NULL;
        return 1;
    }
}

ULONG_ ComputeCloseBox::AddRef_()
{
    this->countLinks++;
    printf("AddRefCloseBox:%d\n", this->countLinks);
    return 0;
}

ULONG_ ComputeCloseBox::Release_()
{
    this->countLinks--;
    printf("ReleaseCloseBox:%d\n", this->countLinks);
    if (this->countLinks <= 0)
    {
        delete this;
        printf("LINKS IS 0! DROPED!\n");
    }
    return 0;
}
