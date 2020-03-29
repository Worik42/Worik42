#include "IClassFactoryCloseBox.h"
#include "ComputeCloseBox.h"

IClassFactoryCloseBox::IClassFactoryCloseBox()
{
    this->countLinks = 0;
    this->AddRef_();
};

HRESULT_ IClassFactoryCloseBox::CreateInstance(IID_ &iid, void **ppv)
{
    ComputeCloseBox *ccB = new ComputeCloseBox();
    HRESULT_ res;
    if (iid == 1 || iid == 2)
    {
        printf("Create Instance CloseBox\n");
        res = ccB->QueryInterface_(iid, ppv);
        return res;
    }
    else
    {
        *ppv = NULL;
        return 1;
    }
}

HRESULT_ IClassFactoryCloseBox::QueryInterface_(IID_ &iid, void **ppv)
{
    printf("FabricCloseBoxQueryInterface:%d\n", iid);
    if (iid == -1)
    {
        *ppv = (void *)(IClassFactory_ *)this;
        this->AddRef_();
        return 0;
    }
    else if (iid == -2)
    {
        *ppv = (void *)(IClassFactoryCloseBox *)this;
        this->AddRef_();
        return 0;
    }
    *ppv = NULL;
    return 1;
}

ULONG_ IClassFactoryCloseBox::AddRef_()
{
    this->countLinks++;
    printf("FabricCloseBoxAddRef:%d\n", this->countLinks);
    return 0;
}

ULONG_ IClassFactoryCloseBox::Release_()
{
    this->countLinks--;
    printf("FabricCloseBoxRelease:%d\n", this->countLinks);
    if (this->countLinks <= 0)
    {
        delete this;
        printf("CloseBox no links\n");
    }
    return 0;
}
