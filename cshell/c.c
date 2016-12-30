#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

int main( ) {
    FILE *fp;

    fp = fopen("/tmp/test.txt", "w+");
    
//    fputc(33, fp);
//    fprintf(fp, "This is testing for fprintf...\n");
//    fputs("This is testing for fputs...\n", fp);
    fclose(fp);

    return 0;
//    int c;
//
//    printf( "Enter a value :");
//    c = getchar( );
//
//    printf( "\nYou entered: ");
//    putchar( c );
//    printf( "\nYou entered: %d \n", c);
//    putchar(97);
//
//    return 0;
}

//int main() {
//
//    struct bs {
//        unsigned a:1;
//        unsigned b:4;
//        unsigned c:4;
//    } bit, *pbit;
//
//    bit.a = 1;
//    bit.b = 15;
//    bit.c = 15;
//
//    printf("%d, %d, %d \n", bit.a, bit.b, bit.c);
//
//    pbit = &bit;
//    pbit->a = 0;
//    pbit->b = 14;
//    pbit->c = 13;
//
//    printf("%d, %d, %d \n", pbit->a, pbit->b, pbit->c);
//    printf("%d, %d, %d \n", (&bit)->a, (&bit)->b, bit.c);
//
//
////    /* 我的第一个 C 程序 */
////    int value=5;
////    int* p=&value;
////    int& r=value;
////
////    printf("pointer is %d, reference is %d", p, r);
////
////    return 0;
////
////
////
////    int num, result;
////    int* point;
////    num = 128;
////    result = num>>1;
////    printf("num is  %d, and result is %ld \n", num, point);
////
////
////    return 0;
//}

