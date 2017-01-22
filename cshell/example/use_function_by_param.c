#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <string.h>
//#include "include/common.h"

void print ( int x ) 
{
    printf("%d\n", x);
}

void func ( void (*f)(int) ) 
{
    int ctr;
    for ( ctr = 0 ; ctr < 5 ; ctr++ ) {
        (*f)(ctr);
    }
}

int main( ) 
{
    func(print);
    return 0;
}
