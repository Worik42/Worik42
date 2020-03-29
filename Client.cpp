#include "GlobalTypes.h"
#include "IClassFactory.h"
#include "BoxModel.h"
#include "IComputeBox.h"

int main()
{
    printf("Start\n");
    HRESULT_ res;
    CLSID_ clsid;
    IID_ iid;
    printf("\n\nCLOSEDBOX\n\n");
    IClassFactory_ *cft;
    clsid = 1;
    iid = -1;
    res = GetClassObject(clsid, iid, (void **)&cft);
    if (res == 0)
    {
        BoxModel *bM;
        iid = 1;
        res = cft->CreateInstance(iid, (void **)&bM);

        if (res == 0)
        {
            bM->setMeasures(300, 750, 450, 12, 149);

            IComputeBox *cB;
            iid = 2;
            res = bM->QueryInterface_(iid, (void **)&cB);

            if (res == 0)
            {
                cB->computeDirtyMeasuresBox();
                bM->printMeasuresBox();

                cB->Release_();
                bM->Release_();
                cft->Release_();
            }
        }
    }

    printf("\n\nBassReflex\n\n");
    IClassFactory_ *cfs;
    clsid = 2;
    iid = -1;
    res = GetClassObject(clsid, iid, (void **)&cfs);
    if (res == 0)
    {
        BoxModel *bM;
        iid = 1;
        res = cfs->CreateInstance(iid, (void **)&bM);

        if (res == 0)
        {
            bM->setMeasures(300, 750, 450, 12, 149);

            IComputeBox *cB;
            iid = 2;
            res = bM->QueryInterface_(iid, (void **)&cB);

            if (res == 0)
            {
                cB->computeDirtyMeasuresBox();
                bM->printMeasuresBox();

                cB->Release_();
                bM->Release_();
                cfs->Release_();
            }
        }
    }
    return 0;
}
