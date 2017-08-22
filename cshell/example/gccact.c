/**
 * 这是一个看自动编译并执行脚本的命令
 * 具体使用规则类似 :
 * > gccact dd/dd/xxx.c -l -t
 * 默认为当前活动目录下的文件
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef  TOOL_H
#include "../include/tool.h"
#endif

#ifndef  FILEFUNC_H
#include "../include/filefunc.h"
#endif


int main ( int argc, char *argv[] )
{
    char path[120];
    char params[120];
    char command[128]="";
    //获取当前参数
    strcpy( path, argv[1] );
    //获取参数路径
    getRealPath( path );
    //验证文件权限
    fileAccess( path, "fr" );

    //将命令参数格式化
    int i = 2;
    while ( argv[i] != NULL) {
        strcat( params, " " );
        strcat( params, argv[i] );
        i++;
    }

    //命令组装
    sprintf( command, "gcc -o /tmp/action %s %s;/tmp/action", path, params );
    system( command );
    return EXIT_SUCCESS;
}
