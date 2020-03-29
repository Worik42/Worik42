#include "IClassFactory.h"

class IClassFactoryBassReflex : public IClassFactory_
{
private:
    int countLinks;

public:
    IClassFactoryBassReflex();
    HRESULT_ CreateInstance(IID_ &, void **);
    HRESULT_ QueryInterface_(IID_ &, void **);
    ULONG_ AddRef_();
    ULONG_ Release_();
};
