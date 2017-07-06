/**
 * 这是一个看自动编译并执行脚本的命令
 * 具体使用规则类似 :
 * > gccact -f xxx.c -d target_dir
 * 默认为当前活动目录下的文件
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main ( int argc, char *argv[] )
{
    char pwd[120];
    getcwd( pwd, sizeof(pwd) );

    int i;
    char *file="";
    char *dir="";
    char command[128]="";
    char path[128] = "";

    dir = pwd;
    for( i=0; i<argc; i++ ) {
        if( i==0 ) continue;
        if( strcmp( argv[i], "-f" ) == 0 ) {
            if( ++i >= argc ) break;
            file = argv[i];
        } else if ( strcmp( argv[i], "-d" ) == 0 ) {
            if( ++i >= argc ) break;
            dir = argv[i];
        }
    }

//printf( ">>%d, %d\n", strlen(file) , strlen(dir) );
    if( strlen(file) <= 0 ||  strlen(dir) <= 0 ) {
        puts( "参数异常" );
        return EXIT_FAILURE;
    }
    sprintf( path, "%s/%s", dir, file );
//puts( path );
    
    // gcc -o action xx.c; ./action
    sprintf( command, "gcc -o /tmp/action %s;/tmp/action", path );
    system( command );
//    puts( command );

    return EXIT_SUCCESS;
}
