#include "../include/bashcolorsets.h"
#include "../include/common.h"
#include "../include/linklist.h"

#define TODO_LOG "/schedule.log"
#define WORK_DIR "/workshell/cshell/schedule"
#define SEPERATE_TODO ";;;"
#define DISABLE_FLAG "#"

struct linkobj {
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
void explodeLine(char *line, struct linkobj *todo) 
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
    struct linkobj todo;
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
    unsigned long current_time_stamp;
    char line_flag[]=" ";
    char line_bak[LINE_NUM];
    int len = 0;

    todo_path = getTodoPath();
//printf("%s", todo_path); exit(0);

    fp = fopen(todo_path, F_READWRTE);
    current_time_stamp = GetCurrentTimeStamp();

    struct linklist *todo_job  = linkInit();
    struct linklist *doing_job = linkInit();
    struct linklist *done_job  = linkInit();
    struct linkobj *todo;
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

        todo = (struct linkobj *)malloc( sizeof(struct linkobj) );
        explodeLine( line_bak, todo );


        //进行时( 未来一天内要做的事 )
        if ( current_time_stamp < todo->time_stamp && ( todo->time_stamp - current_time_stamp ) < DAY_TIME ) {
            if( doing_job->item==NULL ) {
                linkCreate( doing_job, todo  );
            } else {
                linkAppend( doing_job, todo );
            }
        //将来时( 未来二至三天内要做的事 )
        } else if ( current_time_stamp < todo->time_stamp && ( todo->time_stamp - current_time_stamp ) < THREE_DAY_TIME ) {
            if( todo_job->item==NULL ) {
                linkCreate( todo_job, todo  );
            } else {
                linkAppend( todo_job, todo );
            }
        //完成时( 前三天内要做的事 )
        } else if ( current_time_stamp > todo->time_stamp && ( current_time_stamp -todo->time_stamp  ) < THREE_DAY_TIME ) {
            if( done_job->item==NULL ) {
                linkCreate( done_job, todo  );
            } else {
                linkAppend( done_job, todo );
            }
//        } else if ( current_time_stamp > todo->time_stamp ) {
//            if( done_job->item==NULL ) {
//                linkCreate( done_job, todo  );
//            } else {
//                linkAppend( done_job, todo );
//            }
        }

        len += strlen( line );
        fseek( fp, len, SEEK_SET );
    }
    fclose(fp);

    todo_job  = linkReset( todo_job );
    doing_job = linkReset( doing_job );
    done_job  = linkReset( done_job );

    while( todo_job->item ) {
        printf( "\n未开始 >>\n提示事件 : %s%s%s,\n提示备注 : %s%s%s,\n执行地点 : %s%s%s,\n执行时间 : %s%s %s%s \n###################\n" ,
            COLOR_LIGHT_BLUE, todo_job->item->message, COLOR_NC,
            COLOR_LIGHT_BLUE, todo_job->item->note, COLOR_NC,
            COLOR_CYAN, todo_job->item->address, COLOR_NC,
            COLOR_PURPLE, todo_job->item->date, todo_job->item->time, COLOR_NC );
        todo_job = linkNext( todo_job );
    }

    while( doing_job->item ) {
        printf( "\n进行中 >>\n提示事件 : %s%s%s,\n提示备注 : %s%s%s,\n执行地点 : %s%s%s,\n执行时间 : %s%s %s%s \n###################\n" ,
            COLOR_LIGHT_GREEN, doing_job->item->message, COLOR_NC,
            COLOR_LIGHT_BLUE, doing_job->item->note, COLOR_NC,
            COLOR_CYAN, doing_job->item->address, COLOR_NC,
            COLOR_PURPLE, doing_job->item->date, doing_job->item->time, COLOR_NC );
        doing_job = linkNext( doing_job );
    }

    while( done_job->item ) {
        printf( "\n已过时 >>\n提示事件 : %s%s%s,\n提示备注 : %s%s%s,\n执行地点 : %s%s%s,\n执行时间 : %s%s %s%s \n###################\n" ,
            COLOR_LIGHT_RED, done_job->item->message, COLOR_NC,
            COLOR_LIGHT_BLUE, done_job->item->note, COLOR_NC,
            COLOR_CYAN, done_job->item->address, COLOR_NC,
            COLOR_PURPLE, done_job->item->date, done_job->item->time, COLOR_NC );
        done_job = linkNext( done_job );
    }

}



