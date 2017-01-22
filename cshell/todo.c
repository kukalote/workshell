#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>
#include "include/bashcolorsets.h"
#include "include/common.h"
#include "include/config.h"

#define TODO_LOG  "workshell/cshell/todo.txt"

const char s[4] = ";;;";

struct Todo {
    char * message;
    char * address;
    char * note;
    char * date;
    char * time;
    unsigned long time_stamp;
};


char * getTodoPath(void);    
void explodeLine(char * line, struct Todo *todo);
void showTodoLog();

int main( void ) {
    showTodoLog();
    return 0;
}

void showTodoLog( )
{
    FILE *fp;
    char *todo_path;
    char line[255];
    struct Todo todo;
    unsigned long now_time_stamp;

    todo_path = getTodoPath();
//printf("%s", todo_path); exit(0);

    fp = fopen(todo_path, "r");
    while (fgets(line, 255, (FILE*)fp)) {
        explodeLine(line, &todo);    
        now_time_stamp = GetCurrentTimeStamp();

        if(todo.time_stamp - now_time_stamp < THREE_DAY_TIME) {
            printf( "\n提示事件 : %s%s%s,\n提示备注 : %s%s%s,\n执行地点 : %s%s%s,\n执行时间 : %s%s %s%s \n###################\n" ,
                COLOR_LIGHT_RED, todo.message, COLOR_NC,
                COLOR_LIGHT_BLUE, todo.note, COLOR_NC,
                COLOR_CYAN, todo.address, COLOR_NC,
                COLOR_PURPLE, todo.date, todo.time, COLOR_NC);
        }
    }
    fclose(fp);
}


char * getTodoPath( void ){
    char *home;
    home = getenv("HOME");
    strcat(home, "/");
    strcat(home, TODO_LOG);
    return home;
}


void explodeLine(char * line, struct Todo *todo) 
{
    todo->date = strtok(line, s);
    if( todo->date != NULL ) {
        todo->time = strtok(NULL, s);
        todo->message = strtok(NULL, s);
        todo->address = strtok(NULL, s);
        todo->note = strtok(NULL, s);
        strtok(todo->note, "\n");
        todo->time_stamp = Str2TimeStamp(todo->date, todo->time);
//printf("%s, %s, %d---%s---%s---%s---", todo->date, todo->time, todo->time_stamp, todo->message, todo->address, todo->note);
//exit(0);
    }
}

