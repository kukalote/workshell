#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "config.h"
#include "tool.h"





unsigned long GetTick(int iY,int iM,int iD,int iH,int iMin,int iS);

// 通过时间字符串生成时间戳
unsigned long Str2TimeStamp(char * date, char * time) 
{
    char date_bak[22];
    char time_bak[14];

    int year;
    int month;
    int day;

    int hour;
    int min;
    int sec;
    char date_s[2] = "-";
    char time_s[2] = ":";

    unsigned long time_stamp;

    strcpy(date_bak, date);
    strcpy(time_bak, time);

    year = atoi(strtok(date_bak, date_s));
    month = atoi(strtok(NULL, date_s));
    day  = atoi(strtok(NULL, date_s));


    hour = atoi(strtok(time_bak, time_s));
    min = atoi(strtok(NULL, time_s));
    sec  = atoi(strtok(NULL, time_s));
    time_stamp = GetTick(year, month, day, hour, min, sec);
    return time_stamp;
}

//输入各自时间，返回时间戳
unsigned long GetTick(int iY,int iM,int iD,int iH,int iMin,int iS) 
{
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


//返回当前时间至1970-01-01时间戳
unsigned long GetCurrentTimeStamp(void) 
{
    time_t second;
    second = time(NULL);
    return (unsigned long)second;
}

FILE *openFile( char *file_path, char *mode )
{
    FILE *fp;
    fp = fopen( file_path, mode );
    return fp;
}

void closeFile( FILE *fp )
{
    fclose( fp );
}

void writeOption( FILE *fp )
{
    char input_content[LINE_NUM];
    fgets( input_content, LINE_NUM, stdin );
    fputs( input_content, fp );
}
void writeFile( FILE *fp, char *content )
{
    fputs( content, fp );
}


void substr( char *src, int start, int len ) 
{
    int current = 0;
    char *p = src;
    char *q = src;

    p += start;

    while( *p ) {
        if( current < len ) {
            *q++ = *p;
        }
        current++;
        p++;
    }
    *q = '\0';
}

void strRemoveChar( char* str,char ch )
{
    char *p = str;
    char *q = str;
    while(*q) {
        if (*q !=ch) {
            *p++ = *q;
        }
        q++;
    }
    *p = '\0';
} 


void formatData( char *date )
{
    char format_date[11];
    char *has_flag = strpbrk( date, "-" );
    int len = strlen(date);

    if( !has_flag && len==8 ) {
        sprintf( format_date, "%c%c%c%c-%c%c-%c%c\0", date[0], date[1],
            date[2], date[3] ,
            date[4], date[5] ,
            date[6], date[7] );
        strcpy( date, format_date );
    }
//    printf("%s", format_date);
}

void formatTime( char *time )
{
    char format_time[9];
    char *has_flag = strpbrk( time, ":" );
    int len = strlen(time);

    if( !has_flag && (len==6 || len==4) ) {
        sprintf( format_time, "%c%c:%c%c:00", time[0], time[1],
            time[2], time[3] );
        strcpy( time, format_time );
    }
//    printf("%s", format_time);
}
