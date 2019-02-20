#include "date.h"
#include "time.h"
class cupon
{
public:
    int regNumberH[2] = {0, 0};
    int regNumberL[6] = {0, 0, 0, 0, 0, 0};
    char FIO[25];
    date* cuponDay = nullptr;
    time* coponTime = nullptr;
}