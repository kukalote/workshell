#include <stdio.h>
#include <stdlib.h>
#include <string.h>




char *getStr()
{
//    char array[33] = "hello c world";
//    memset(array, '\0', strlen(array));
//    strcpy(array, "hello c world");

//    char *str = &array;
//    char *str = "hello c world";
//    return *array;
//    return array;
}



//@todo 试生成字符指针为元素的数组
char **explode( char *input, char *split )
{
//    char *ceil = strtok(input, split);
//    char *array[3];
//    char **result;
//    int key = 0;
//    array[key] = (char *)malloc( (strlen(ceil) + 1)*sizeof(char) );
//    array[key++] = ceil;
//    while( ceil = strtok(NULL, split) ) {
//        array[key] = (char *)malloc( (strlen(ceil) + 1)*sizeof(char) );
//        array[key++] = ceil;
//    }
////    printf(">%s\n", array[1]);
//    result = array;
////    printf(">%s\n", result[1]);
//    return result;
}

char * sstrtok( char *s1, const char *s2 )
{
    char *sbegin, *send;
    static char *ssave = "";

    sbegin = s1 ? s1 : ssave;
    sbegin += strspn( sbegin, s2 );
    if ( *sbegin == '\0' ) {
        ssave = "";
        return (NULL);
    }
    send = sbegin + strcspn( sbegin, s2 );
//    puts(send);
    if( *send != '\0' )
        *send++ = '\0';
    ssave = send;
    return (sbegin);

}

int main()
{
//    char time[30] = "2017-03-01";
//    char s[2] = "-";
//    char *token;
//    token = sstrtok( time, s );
//    puts(token);
//    token = sstrtok( NULL, s );
//    puts(token);




//    char input[30]="hello,world,c language";
//    char **array;
//    array = explode( input, "," );
//    printf("%s\n", array[0]);
//    printf(">>%s\n", array[1]);
//    printf("%s\n", array[2]);

//    char *str;
//    str = getStr();
//    printf("%s\n", str);

//    char *output = strtok(input, ",");
//    printf("%s<<\n", output);
//    output = strtok(NULL, ",");
//    printf("%s<<\n", output);
return 0;
}
