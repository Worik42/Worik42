#ifndef D4DA0CF7_171E_4187_8214_EF18E0AA2724
#define D4DA0CF7_171E_4187_8214_EF18E0AA2724

#include "GlobalTypes.h"
#include "IUnknown.h"

class IClassFactory_ : public IUnknown_
{
public:
    virtual HRESULT_ CreateInstance(IID_ &, void **) = 0;
};
#endif /* D4DA0CF7_171E_4187_8214_EF18E0AA2724 */
