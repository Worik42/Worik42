#include "IClassFactory.h"

class IClassFactoryCloseBox : public IClassFactory_ {
private:
    int countLinks;
public:
    IClassFactoryCloseBox();
    HRESULT_  CreateInstance(IID_ &, void **);
    HRESULT_  QueryInterface_(IID_ &, void **);
    ULONG_  AddRef_();
    ULONG_  Release_();
};
