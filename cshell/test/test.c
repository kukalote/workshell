#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//@todo 试生成字符指针为元素的数组
char * explode( char *input, char *split )
{
    char *ceil = strtok(input, split);
//    printf( "%s\n", output );
    char *array;
    while( ceil = strtok(NULL, ",") ) {
//        printf( "%s\n", output );
    }
}

int main()
{
    char input[30];
    scanf("%s", &input);
    explode( input, "," );

//    char *output = strtok(input, ",");
//    printf("%s<<\n", output);
//    output = strtok(NULL, ",");
//    printf("%s<<\n", output);
return 0;
}
