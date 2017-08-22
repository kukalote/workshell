#include <unistd.h>
#include <string.h>
#define TOOL_H 'cshell/include/tool.h'
/**
 * @note 输出字符串
 */
void ds(char *str)
{
    printf( "%s", str );
    exit(1);
}
/**
 * @note 输出整数
 */
void dd( int intval)
{
    printf( "%d", intval );
    exit(1);
}

/**
 * @note 输出字符串长度
 */
void dsl( char *str )
{
    printf( "%d\n", strlen(str) );
    exit(1);
}


/**
 * @note 获取当前操作路径
 */
void getCurrentPath( char *path )
{
    char pwd[120];
    getcwd( pwd, sizeof(pwd) );
    strcpy( path, pwd );
}

/**
 * @note 将指定文件目录转换成绝对文件目录
 */
void getRealPath( char *path )
{
    char real_path[120];
    char current_path[60];
    int ret;
    // "/" 开头
    ret = strncmp( path, "/", 1 );
    if( ret != 0 ) {
        // "./" 开头的
        ret = strncmp( path, "./", 2 );
        getCurrentPath( current_path );
//        puts( path );
        if( ret == 0 ) {
            strcpy( real_path, path+2 );
        } else {
            strcpy( real_path, path );
        }
        sprintf( path, "%s/%s", current_path, real_path );
        path[strlen(path)] = '\0';
    }
}

/**
 * @note 判断字符串a中是否含有字符串b
 */
int strpos( char *main, char *needle )
{
 
}

/**
 * 字符串数组拼接
 */
//char **connectStringArray(char **input) 
//{
//    char **command = malloc(8 * sizeof(char *));
//    char *separator = " ";
//    char *parsed;
//    int index = 0;
//
//    parsed = strtok(input, separator);
//    while (parsed != NULL) {
//        command[index] = parsed;
//        index++;
//
//        parsed = strtok(NULL, separator);
//    }
//
//    command[index] = NULL;
//    return command;
//}
