#include <fcntl.h>
#ifndef TOOL_H
#include "../include/tool.h"
#endif

#define FILEFUNC_H 'cshell/include/filefunc.h'


/**
 * @note 判断文件权限
 * @param string  access  f,r,rw,rwx
 */
void fileAccess( char *path, char *accesses )
{
    //验证文件的可执行性
    if( strchr(accesses, 'f')!=NULL && access( path, F_OK ) != 0 ) {
        printf( "%s 文件不存在", path );
        exit(1);
    }
    if( strchr(accesses, 'r')!=NULL && access( path, R_OK ) != 0 ) {
        printf( "%s 文件不可读", path );
        exit(1);
    }
    if( strchr(accesses, 'w')!=NULL && access( path, W_OK ) != 0 ) {
        printf( "%s 文件不可写", path );
        exit(1);
    }
    if( strchr(accesses, 'x')!=NULL && access( path, X_OK ) != 0 ) {
        printf( "%s 文件不可执行", path );
        exit(1);
    }
}
