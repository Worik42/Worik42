#include <stdio.h>
#include <iostream>

using namespace std;

typedef int HRESULT_;
typedef int CLSID_;
typedef int IID_;
typedef int ULONG_;

HRESULT_ GetClassObject(CLSID_ &, IID_ &, void **);
