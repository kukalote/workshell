#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>

#define TODO_LOG  "workshell/cshell/todo.txt"
const char s[2] = " ";

struct Todo {
    char * message;
    char * address;
    char * note;
    unsigned long time_stamp;
};

char * getTodoPath(void);    
void explodeLine(char * line, struct Todo *todo);
unsigned long Str2TimeStamp(char * date, char * time);
unsigned long GetTick(int iY,int iM,int iD,int iH,int iMin,int iS);
unsigned long GetCurrentTimeStamp(void);

int main( void ) {
    FILE *fp;
    char *todo_path;
    char line[255];
    struct Todo todo;
    unsigned long now_time_stamp;
    todo_path = getTodoPath();

    fp = fopen(todo_path, "r");
    while (fgets(line, 255, (FILE*)fp)) {
        explodeLine(line, &todo);    
        now_time_stamp = GetCurrentTimeStamp();

//        printf("%d\n", todo.time_stamp); ;
//        printf("%d", now_time_stamp); exit(0);


        if(todo.time_stamp - now_time_stamp < 86400) {
            printf("请处理事件<%s>, 时间执行时间为 xxx \n", todo.message);
        }
//        printf("%d",todo.time_stamp - now_time_stamp );
    }
    fclose(fp);
//    fputc(33, fp);
//    fprintf(fp, "This is testing for fprintf...\n");
//    fputs("This is testing for fputs...\n", fp);

    return 0;
}



char * getTodoPath( void ){
    char *home;
    home = getenv("HOME");
    strcat(home, "/");
    strcat(home, TODO_LOG);
    return home;
}


void explodeLine(char * line, struct Todo *todo) {
    char * date;
    char * time;

    date = strtok(line, s);
    if( date != NULL ) {
        time = strtok(NULL, s);
        todo->message = strtok(NULL, s);
        todo->address = strtok(NULL, s);
        todo->note = strtok(NULL, s);
        todo->time_stamp = Str2TimeStamp(date, time);
//printf("%d\n%s\n%s\n%s", todo->time_stamp, todo->message, todo->address, todo->note);
//exit(0);
    }
    return;
}

unsigned long Str2TimeStamp(char * date, char * time) {

    int year;
    int month;
    int day;

    int hour;
    int min;
    int sec;
    char date_s[2] = "-";
    char time_s[2] = ":";

    unsigned long time_stamp;

    year = atoi(strtok(date, date_s));
    month = atoi(strtok(NULL, date_s));
    day  = atoi(strtok(NULL, date_s));

    hour = atoi(strtok(time, time_s));
    min = atoi(strtok(NULL, time_s));
    sec  = atoi(strtok(NULL, time_s));
    
    time_stamp = GetTick(year, month, day, hour, min, sec);
    return time_stamp;
}
unsigned long GetTick(int iY,int iM,int iD,int iH,int iMin,int iS) {
    struct tm stm;

    memset(&stm,0,sizeof(stm));

    stm.tm_year=iY-1900;
    stm.tm_mon=iM-1;
    stm.tm_mday=iD;
    stm.tm_hour=iH-8;
    stm.tm_min=iMin;
    stm.tm_sec=iS;

    return (unsigned long) mktime(&stm);
}

unsigned long GetCurrentTimeStamp(void) {
    time_t second;
    second = time(NULL);
    return (unsigned long)second;
}