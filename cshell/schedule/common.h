#include "../include/bashcolorsets.h"
#include "../include/common.h"

#define TODO_LOG "/schedule.log"
#define WORK_DIR "/workshell/cshell/schedule"
#define SEPERATE_TODO ";;;"
#define DISABLE_FLAG "#"

struct Todo {
    char message[30];
    char address[30];
    char note[20];
    char date[11];
    char time[9];
    unsigned long time_stamp;
};

//struct SCHEDULE_LIST {
//    struct Todo *data;
//    struct SCHEDULE_LIST *next;
//};

// 获取日程记录地址
char *getTodoPath( void )
{
    char *home = getenv( "HOME" );
    strcat( home, WORK_DIR );
    strcat( home, TODO_LOG );
    return home;
}
void explodeLine(char *line, struct Todo *todo) 
{
    strcpy( todo->date, strtok(line, SEPERATE_TODO) );
    if( todo->date != NULL ) {
        strcpy( todo->time, strtok(NULL, SEPERATE_TODO) );
        strcpy( todo->message, strtok(NULL, SEPERATE_TODO) );
        strcpy( todo->address, strtok(NULL, SEPERATE_TODO) );
        strcpy( todo->note, strtok(NULL, SEPERATE_TODO) );
        strtok( todo->note, "\n" );
        todo->time_stamp = Str2TimeStamp(todo->date, todo->time);
//printf("%s, %s, %d---%s---%s---%s---", todo->date, todo->time, todo->time_stamp, todo->message, todo->address, todo->note);
//exit(0);
    }
}
char *inputProgram( char *todo_line )
{
    struct Todo todo;
    //提示用户输出,并先输出格式
    printf( "Enter the todo jobs : \n");

    printf( "\ninput your todo job date, format like this : \"20170101\"\n");
    fgets( todo.date, LINE_NUM, stdin );
    todo.date[strlen(todo.date)-1] = STRING_END;
    formatData(todo.date);

    printf( "\ninput your todo job time, format like this : \"2359\"\n");
    fgets( todo.time, LINE_NUM, stdin );
    todo.time[strlen(todo.time)-1] = STRING_END;
    formatTime(todo.time);

    printf( "\ninput your todo job message, format like this : \"my message\" \n");
    fgets( todo.message, LINE_NUM, stdin );
    todo.message[strlen(todo.message)-1] = STRING_END;

    printf( "\ninput your todo job address, format like this : \"my address\" \n");
    fgets( todo.address, LINE_NUM, stdin );
    todo.address[strlen(todo.address)-1] = STRING_END;

    printf( "\ninput your todo job note, format like this : \"my note\" \n");
    fgets( todo.note, LINE_NUM, stdin );
    todo.note[strlen(todo.note)-1] = STRING_END;

    sprintf( todo_line, " %s;;;%s;;;%s;;;%s;;;%s\n", todo.date, todo.time, todo.message, todo.address, todo.note);
    printf( "finish your input\n" );
}



void showTodoLog( )
{
    FILE *fp;
    char *todo_path;
    char line[LINE_NUM];
    char line_str[LINE_NUM] ;
    struct Todo todo;
    unsigned long current_time_stamp;
    char line_flag[]=" ";
    char line_bak[LINE_NUM];
    int len = 0;

    todo_path = getTodoPath();
//printf("%s", todo_path); exit(0);

    fp = fopen(todo_path, F_READWRTE);
    current_time_stamp = GetCurrentTimeStamp();

    
    while ( fgets(line, LINE_NUM, (FILE*)fp) ) {
        fseek( fp, len, SEEK_SET );
        strncpy( line_flag, line, 1 );
        strcpy( line_bak, line );
        substr( line_bak, 1, strlen(line)-1 );

        if( strcmp(line_flag, DISABLE_FLAG) == 0 ) {
            len += strlen( line );
            fseek( fp, len, SEEK_SET );
            continue;
        }

        strcpy( line_str, line_bak );
        explodeLine( line_bak, &todo );    

        //提醒期
        //将执行，提示(3天之前)
        //准备执行,提示(3天内 )
        //已过时,提示(过时3天内)
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
            fputs( DISABLE_FLAG, fp );
        }
        len += strlen( line );
        fseek( fp, len, SEEK_SET );
    }
    fclose(fp);
}



