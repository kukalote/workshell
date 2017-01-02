#include <stdio.h>
#include <time.h>
#include <string.h>

long GetTick(int iY,int iM,int iD,int iH,int iMin,int iS)
{
    struct tm stm;

    memset(&stm,0,sizeof(stm));

    stm.tm_year=iY-1900;
    stm.tm_mon=iM-1;
    stm.tm_mday=iD;
    stm.tm_hour=iH-8;
    stm.tm_min=iMin;
    stm.tm_sec=iS;

    return mktime(&stm);
}

int main()
{
    printf("%d\n", GetTick(2017,1,1,2,1,1));
    return 0;    
}
