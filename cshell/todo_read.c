#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>
#include "include/common.h"

#define TODO_LOG  "workshell/cshell/todo.txt"
const char s[2] = " ";

struct Todo {
    char message[255];
    char address[255];
    char note[255];
    char date[11];
    char time[9];
    unsigned long time_stamp;
};

char * getTodoPath(void);    

int main( void ) {
    struct Todo todo;
//    char *mode = "a";
    char seperator[4] = ";;;";

    //todo记录文件
    char *todo_path;
    todo_path = getTodoPath();

    //提示用户输出,并先输出格式
    printf( "Enter the todo jobs : \n");

    printf( "\ninput your todo job date, format like this : \"2016-01-01\"\n");
    fgets( todo.date, LINE_NUM, stdin );
    todo.date[strlen(todo.date)-1] = STRING_END;
//printf( "%d \n%s<<",strlen(todo.date),  todo.date );
//exit(0);
    printf( "\ninput your todo job time, format like this : \"12:01:01\"\n");
    fgets( todo.time, LINE_NUM, stdin );
    todo.time[strlen(todo.time)-1] = STRING_END;

    printf( "\ninput your todo job message, format like this : \"my message\" \n");
    fgets( todo.message, LINE_NUM, stdin );
    todo.message[strlen(todo.message)-1] = STRING_END;

    printf( "\ninput your todo job address, format like this : \"my address\" \n");
    fgets( todo.address, LINE_NUM, stdin );
    todo.address[strlen(todo.address)-1] = STRING_END;

    printf( "\ninput your todo job note, format like this : \"my note\" \n");
    fgets( todo.note, LINE_NUM, stdin );
    todo.note[strlen(todo.note)-1] = STRING_END;

    char todo_line[LINE_NUM];
    sprintf( todo_line, "%s;;;%s;;;%s;;;%s;;;%s\n", todo.date, todo.time, todo.message, todo.address, todo.note);

    FILE *fp;
    fp = openFile( todo_path, APPEND_FILE );
    writeFile( fp, todo_line );
    closeFile( fp );

    printf( "finish your input" );
//printf( "%s", todo_line );
//printf("%d, %s, %s, %s", todo.time_stamp, todo.message, todo.address, todo.note);
    return 0;
}




char * getTodoPath( void ){
    char *home;
    home = getenv("HOME");
    strcat(home, "/");
    strcat(home, TODO_LOG);
    return home;
}

