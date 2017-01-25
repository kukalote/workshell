#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "../include/config.h"
#include "../include/common.h"
#include "../schedule/common.h"


int main( void ) 
{
    char todo_line[LINE_NUM];
    FILE *fp;
    char *todo_path = getTodoPath();

    inputProgram( todo_line );

    fp = openFile( todo_path, FILE_MODE_APPEND );
    writeFile( fp, todo_line );
    closeFile( fp );
//    printf( ">>%s<<\n", todo_line );
    return 0;
}

