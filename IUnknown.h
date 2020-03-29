#ifndef D29230F7_7C56_4911_8F19_EB1900A52577
#define D29230F7_7C56_4911_8F19_EB1900A52577

#include "GlobalTypes.h"

class IUnknown_
{
public:
    virtual HRESULT_ QueryInterface_(IID_ &, void **) = 0;
    virtual ULONG_ AddRef_() = 0;
    virtual ULONG_ Release_() = 0;
};
#endif /* D29230F7_7C56_4911_8F19_EB1900A52577 */
