#include <stdio.h>
#include <unistd.h>
#include <string.h>
#define TOOL_H 1

#define dp(code, msg) \
    printf("\nFile %s \nline:%d\ncode=%d\nmsg=%s\n", __FILE__, __LINE__, code, #msg); \
    _exit( code ); 

void ds( char *str, int is_exit );
void dd( int intval);
void dsl( char *str );
void getCurrentPath( char *path );
void getRealPath( char *path );
int strpos( char *main, char *needle );
int getDateMode( char *date );
void analyzeDateFormat( char *date, char *dates[] );
void explode( char *src, char *separator, char *dest[] );
void explodeByCount( char *src, int separator_arr[], char *dest[] );

/**
 * @note 输出字符串
 */
void ds(char *str, int is_out)
{
    printf( "%s", str );
    if( is_out==1 ) 
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

/**************************************************/
/******************时间相关函数********************/
/**************************************************/

void analyzeDateFormat( char *date, char *dates[] )
{
    int mode;
    mode = getDateMode( date );
    if( mode == 1 ) {
        char *separator = "-";
        explode( date, separator, dates );
    } else if( mode == 2 ) {
        char *separator = "/";
        explode( date, separator, dates );
    } else if( mode == 3 ) {
        int separator_arr[3] = {4, 2, 2, NULL};
        explodeByCount( date, separator_arr, dates );
    ds( dates[1], 1 );
    ds( ">>>>", 0 );
    }
}

/**
 * @note 判断传入时间格式
 * 类型1 : Y-M-D
 * 类型2 : Y/M/D
 * 类型3 : YMD
 */
int getDateMode( char *date )
{
    int mode;
    int str_len = strlen(date);
    if( strchr( date, '-' ) != NULL && str_len == 10 ) {
        mode = 1;
    } else if ( strchr( date, '/' ) != NULL && str_len == 10 ) {
        mode = 2;
    } else if ( str_len == 8 ) {
        mode = 3;
    } else {
        dp( 0, "请输入正确日期格式" );
    }
    return mode;
}

/**************************************************/
/******************时间相关函数********************/
/**************************************************/

/**
 * @note 以指定字符分隔标识符
 */
void explode( char *src, char *separator, char *dest[] )
{
    char *parsed;
    int index = 0;
    parsed = strtok(src, separator);
    while (parsed != NULL) {
        dest[index] = parsed;
        index++;

        parsed = strtok(NULL, separator);
    }

    dest[index] = NULL;
}

/**
 * @note 根据指定字符长度分割为数组
 */
void explodeByCount( char *src, int separator_arr[], char *dest[] )
{
//    int str_len = strlen( src );    
    int i;
    char ceil[5] = "";
    for( i=0; separator_arr[i]; i++ ) {
        strncpy( ceil, "", 5 );
        strncpy( ceil, src, separator_arr[i] );
        dest[i] = ceil;
        src += separator_arr[i];
    }
    dest[i] = NULL;
    ds( dest[1], 1 );
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
