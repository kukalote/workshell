#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#define TODO_LOG  "/root/workshell/cshell/todo.txt"
const char s[2] = "-";

char * explodeLine(char * line);    

int main( ) {
    FILE *fp;
    char line[255];

    fp = fopen(TODO_LOG, "r");
    while (fgets(line, 255, (FILE*)fp)) {
//        printf("%s \n", line);
        explodeLine(line);    
    }
    fclose(fp);
//    fputc(33, fp);
//    fprintf(fp, "This is testing for fprintf...\n");
//    fputs("This is testing for fputs...\n", fp);

    return 0;
}

char * explodeLine(char * line) {
    char * token;
    token = strtok(line, s);
    printf("%s", token);

    while( token != NULL ) {
        printf( " %s\n", token );

        token = strtok(NULL, s);
    }
    return 0;
    while(++token) {
        printf("%s", token);
    }
    return 0;
}
