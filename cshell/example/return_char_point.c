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


//栈与系统的设计有关，由系统来管理。不过，程序员可以通过如new malloc语句在堆中获取内存。
//
//栈是向下生长的一块连续的内存区域。栈的大小是系统设置好的。堆是向上生长，不连续的内存区域。因为操作系统是用链表来管理内存的。
//
//堆的大小受系统有效虚拟内存的限制。
//
//栈： 在函数调用时，第一个进栈的是主函数中函数调用后的下一条指令的地址，然后是函数的各个参数，注意静态变量是不入栈的。当本次函数调用结束后，局部变量先出栈
//，然后是参数，最后栈顶指针指向最开始存的地址，也就是主函数中的下一条指令，程序由该点继续运行。
//
//堆：堆中的具体内容有程序员安排。

//无法正常返回的情况
char *getFailStr()
{
//    char *str0 = "hello world failed";      //内容存放在堆中
//    char str0[30] = "hello world failed"; //在局部声明的空间不可用
    char *str_t = "hello world failed";
    char *str0 = str_t;
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
