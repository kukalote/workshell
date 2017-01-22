#include <stdio.h>
#include <time.h> 

static clock_t start_t, end_t;
clock_t timeStart(void);
clock_t timeEnd(void);
float timeTotal(void);

int main()
{
    /* 我的第一个 C 程序 */
    float total_t;
    long start, end;

    start = 1;
    end = 500000000;

    start_t = timeStart();
    for(;start<end;start++) 
        ;
    end_t = timeEnd();

    total_t = timeTotal();

    printf("program start time %ld \n", start_t);
    printf("program end time %ld \n", end_t);
    printf("program total time %f \n", total_t);
    //printf("%ld \n", CLOCKS_PER_SEC);
    return 0;
}

clock_t timeStart(void) {
    return start_t = clock();
}

clock_t timeEnd(void) {
    return end_t = clock();
}

float timeTotal(void) {
    float total_t;
    return total_t = (double)(end_t-start_t) / CLOCKS_PER_SEC;
}
