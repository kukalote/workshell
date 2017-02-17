#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//函数可以返回字符指针，但请求完成后，函数中的局部变量会清理。
//如果想保持返回的字符指针指向始终有效，有如下几个方法 : 
//
//1. 使用堆空间，返回申请地址(注意释放)。
//2. 函数返回指针指向静态变量(共享)。
//3. 返回全局变量。
//4. 函数参数为返回指针变量。


//无法正常返回的情况
char *getFailStr()
{
    char *str0 = "hello world failed";      //内容存放在堆中
//    char str0[30] = "hello world failed"; //在局部声明的空间不可用
    return str0;
}

//情况1
//char *getMallocStr()
//{
//    char *str1 = malloc( 30*sizeof(char) );
//    str1 = "hello world1";
//    return str1;
//}
//
////情况2
//char *getStaticStr()
//{
//    static char *str2;
//    str2 = "hello world2";
//    return str2;
//}
//
//
int main()
{

    char *str0 = getFailStr();
    printf("%s\n", str0);

//    char *str1 = getMallocStr();
//    printf("%s\n", str1);
//
//    char *str2 = getStaticStr();
//    printf("%s\n", str2);
}
