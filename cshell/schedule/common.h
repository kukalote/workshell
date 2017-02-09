#include "../include/bashcolorsets.h"
#define TODO_LOG "/schedule.log"
#define WORK_DIR "/workshell/cshell/schedule"
#define SEPERATE_TODO ";;;"

struct Todo {
    char *message;
    char *address;
    char *note;
    char *date;
    char *time;
    unsigned long time_stamp;
};

// 获取日程记录地址
char *getTodoPath( void )
{
    char *home = getenv( "HOME" );
    strcat( home, WORK_DIR );
    strcat( home, TODO_LOG );
    return home;
}
void explodeLine(char *line_origin, struct Todo *todo) 
{
    char line[255];
    strcpy( line, line_origin );
    todo->date = strtok(line, SEPERATE_TODO);
    if( todo->date != NULL ) {
        todo->time = strtok(NULL, SEPERATE_TODO);
        todo->message = strtok(NULL, SEPERATE_TODO);
        todo->address = strtok(NULL, SEPERATE_TODO);
        todo->note = strtok(NULL, SEPERATE_TODO);
        strtok(todo->note, "\n");
        todo->time_stamp = Str2TimeStamp(todo->date, todo->time);
printf("%s, %s, %d---%s---%s---%s---", todo->date, todo->time, todo->time_stamp, todo->message, todo->address, todo->note);
exit(0);
    }
}
char *inputProgram( char *todo_line )
{
    struct Todo todo;
    //提示用户输出,并先输出格式
    printf( "Enter the todo jobs : \n");

    char date[10];
    char time[9];
    char message[LINE_NUM];
    char address[LINE_NUM];
    char note[LINE_NUM];


    printf( "\ninput your todo job date, format like this : \"2016-01-01\"\n");
    fgets( date, LINE_NUM, stdin );
    date[strlen(date)-1] = STRING_END;
    todo.date = date;

    printf( "\ninput your todo job time, format like this : \"12:01:01\"\n");
    fgets( time, LINE_NUM, stdin );
    time[strlen(time)-1] = STRING_END;
    todo.time = time;

    printf( "\ninput your todo job message, format like this : \"my message\" \n");
    fgets( message, LINE_NUM, stdin );
    message[strlen(message)-1] = STRING_END;
    todo.message = message;

    printf( "\ninput your todo job address, format like this : \"my address\" \n");
    fgets( address, LINE_NUM, stdin );
    address[strlen(address)-1] = STRING_END;
    todo.address = address;

    printf( "\ninput your todo job note, format like this : \"my note\" \n");
    fgets( note, LINE_NUM, stdin );
    note[strlen(note)-1] = STRING_END;
    todo.note = note;

    sprintf( todo_line, " %s;;;%s;;;%s;;;%s;;;%s\n", todo.date, todo.time, todo.message, todo.address, todo.note);
    printf( "finish your input\n" );
}

void disableTodoLog( FILE *fp, char *line );

int flen = 0;

void showTodoLog( )
{
    FILE *fp;
    char *todo_path;
    char line[255];
    char line_str[255] ;
    struct Todo todo;
    unsigned long current_time_stamp;
    char line_flag[]=" ";
    char line_bak[255];
    int len = 0;

    todo_path = getTodoPath();

    fp = fopen(todo_path, "r+");
    current_time_stamp = GetCurrentTimeStamp();
    while ( fgets(line, LINE_NUM, (FILE*)fp) ) {
        fseek( fp, len, SEEK_SET );
        strncpy( line_flag, line, 1 );
        strcpy( line_bak, line );
        substr( line_bak, 1, strlen(line)-1 );

        if( strcmp(line_flag, "#") == 0 ) {
            len += strlen( line );
            fseek( fp, len, SEEK_SET );
            continue;
        }

        explodeLine( line_bak, &todo );    

        //提醒期
        if( current_time_stamp > todo.time_stamp && (current_time_stamp - todo.time_stamp) < THREE_DAY_TIME ) {
            printf( "\n待执行 >>\n提示事件 : %s%s%s,\n提示备注 : %s%s%s,\n执行地点 : %s%s%s,\n执行时间 : %s%s %s%s \n###################\n" ,
                COLOR_LIGHT_GREEN, todo.message, COLOR_NC,
                COLOR_LIGHT_BLUE, todo.note, COLOR_NC,
                COLOR_CYAN, todo.address, COLOR_NC,
                COLOR_PURPLE, todo.date, todo.time, COLOR_NC );
        } else if( current_time_stamp > todo.time_stamp ) {
            printf( "\n已过时 >>\n提示事件 : %s%s%s,\n提示备注 : %s%s%s,\n执行地点 : %s%s%s,\n执行时间 : %s%s %s%s \n###################\n" ,
                COLOR_LIGHT_RED, todo.message, COLOR_NC,
                COLOR_LIGHT_BLUE, todo.note, COLOR_NC,
                COLOR_CYAN, todo.address, COLOR_NC,
                COLOR_PURPLE, todo.date, todo.time, COLOR_NC );
            fputs( "#", fp );
        }
        len += strlen( line );
        fseek( fp, len, SEEK_SET );
    }
    fclose(fp);
}

void disableTodoLog( FILE *fp, char *line ) 
{
    int fleng;
    flen += strlen( line );
    fseek( fp, flen, SEEK_SET );
    fprintf( fp, "# %s\n",line );
}
