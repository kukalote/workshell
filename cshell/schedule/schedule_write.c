#include "../schedule/common.h"


int main( void ) 
{
    char todo_line[LINE_NUM];
    FILE *fp;
    char *todo_path = getTodoPath();

    inputProgram( todo_line );

    fp = openFile( todo_path, F_APPEND );
    writeFile( fp, todo_line );
    closeFile( fp );
//    printf( ">>%s<<\n", todo_line );
    return 0;
}

