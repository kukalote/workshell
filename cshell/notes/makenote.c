#include "stdio.h"
#include "string.h"

int main( int argc, char *argv[] )
{
    printf("%d", argc);
    int i;
    for( i=0; i<argc; i++ ) {
        printf( "\n%s", argv[i] );
    }
//    int a;
//    for( a = 10; a < 20; a = a + 1 )
//    {
//        printf("a 的值： %d\n", a);
//    }

    return 0;
}
