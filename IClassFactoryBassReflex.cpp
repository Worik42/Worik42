#include "IClassFactoryBassReflex.h"
#include "ComputeBassReflex.h"

IClassFactoryBassReflex::IClassFactoryBassReflex() {
    this->countLinks = 0;
    this->AddRef_();
};

HRESULT_  IClassFactoryBassReflex::CreateInstance(IID_ & iid, void ** ppv) {
    ComputeBassReflex * cbr = new ComputeBassReflex();
    HRESULT_ res;
    if (iid == 1 || iid == 2) {
        printf("Create Instance BassReflex\n");
        res = cbr->QueryInterface_(iid,ppv);
        return res;
    } else {
        * ppv = NULL;
        return 1;
    }
}

HRESULT_ IClassFactoryBassReflex::QueryInterface_(IID_ & iid, void ** ppv) {
    printf("ComputeBassReflex:%d\n",iid);
    if (iid == -1) {
        * ppv = (void *)(IClassFactory_ *) this;
        this->AddRef_();
        return 0;
    } else if (iid == -3) {
        * ppv = (void *)(IClassFactoryBassReflex *) this;
        this->AddRef_();
        return 0;
    }
    * ppv = NULL;
    return 1;
}

ULONG_ IClassFactoryBassReflex::AddRef_()
{
    this->countLinks++;
    printf("FabricBassReflexAddRef:%d\n",this->countLinks);
    return 0;
}

ULONG_ IClassFactoryBassReflex::Release_()
{
    this->countLinks--;
    printf("FabricBassReflexRelease:%d\n",this->countLinks);
    if (this->countLinks <= 0) {
        delete this;
        printf("BassReflex no links\n");
    }
    return 0;
}
