#include "GlobalTypes.h"
#include "IClassFactoryBassReflex.h"
#include "IClassFactoryCloseBox.h"

HRESULT_ GetClassObject(CLSID_ &clsid, IID_ &iid, void **ppv)
{
    HRESULT_ res;
    if (clsid == 1)
    {
        printf("GetClassObject\n");
        IClassFactoryCloseBox *cfbr = new IClassFactoryCloseBox();
        if (iid == -1)
        {
            *ppv = (void *)(IClassFactory_ *)cfbr;
            return 0;
        }
        else if (iid == -3)
        {
            *ppv = (void *)cfbr;
            return 0;
        }
    }
    else if (clsid == 2)
    {
        printf("GetClassObject\n");
        IClassFactoryBassReflex *cfcb = new IClassFactoryBassReflex();
        if (iid == -1)
        {
            *ppv = (void *)(IClassFactory_ *)cfcb;
            return 0;
        }
        else if (iid == -2)
        {
            *ppv = (void *)cfcb;
            return 0;
        }
    }
    *ppv = NULL;
    return 1;
}
