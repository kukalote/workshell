#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>
#include "include/common.h"

#define NEW_LINE 225
//
//struct TODO {
//    char *date;
//    char *time;
//    int  timestamp;
//    char *message;
//    char *address;
//    char *note;
//};
struct TODO {
    char date[10];
    char time[8];
    int  timestamp;
    char message[255];
    char address[255];
    char note[255];
};

int main( void ) 
{
    char *input;
    struct TODO todo;

    printf( "input your words:\n" );

    printf( "input your words:date,like \"2016-10-10\"\n" );
    todo.date = getOption();
    printf( ">>>%s\n", todo.date );

    printf( "input your words:time,like \"22:11:12\"\n" );
    todo.time = getOption();
    printf( ">>>%s\n", todo.time );

    todo.timestamp = Str2TimeStamp( todo.date, todo.time );
    printf( ">>>%d\n", todo.timestamp );

    printf( "input your words:message,like \"message\"\n" );
    todo.message = getOption();
    printf( ">>>%s\n", todo.message );

    printf( "input your words:address,like \"address\"\n" );
    todo.address = getOption();
    printf( ">>>%s\n", todo.address );

    printf( "input your words:note,like \"note\"\n" );
    todo.note = getOption();
    printf( ">>>%s\n", todo.note );
    return 0;
}

