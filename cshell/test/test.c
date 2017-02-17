#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//@todo 试生成字符指针为元素的数组
char **explode( char *input, char *split )
{
    char *ceil = strtok(input, split);
    static char *array[3];
    char **result;
    int key = 0;
    array[key++] = ceil;
    while( ceil = strtok(NULL, split) ) {
        array[key++] = ceil;
    }
//    printf("%x\n", array[0]);
//    printf("%x\n", array[1]);
//    result = array;
    return array;
}

char *getStr()
{
    char array[33] = "hello c world";
//    memset(array, '\0', strlen(array));
//    strcpy(array, "hello c world");

//    char *str = &array;
//    char *str = "hello c world";
    return *array;
//    return array;
}

int main()
{
//    char input[30]="hello,world,c language";
//    char **array;
//    array = explode( input, "," );
//    printf("%s\n", array[0]);
//    printf("%s\n", array[1]);
//    printf("%s\n", array[2]);

    char *str;
    str = getStr();
    printf("%s\n", str);

//    char *output = strtok(input, ",");
//    printf("%s<<\n", output);
//    output = strtok(NULL, ",");
//    printf("%s<<\n", output);
return 0;
}
