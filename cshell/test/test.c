#include <stdio.h>
#include <stdlib.h>
#include <string.h>




char *getStr()
{
//    char array[33] = "hello c world";
//    memset(array, '\0', strlen(array));
//    strcpy(array, "hello c world");

//    char *str = &array;
//    char *str = "hello c world";
//    return *array;
//    return array;
}



//@todo 试生成字符指针为元素的数组
char **explode( char *input, char *split )
{
//    char *ceil = strtok(input, split);
//    char *array[3];
//    char **result;
//    int key = 0;
//    array[key] = (char *)malloc( (strlen(ceil) + 1)*sizeof(char) );
//    array[key++] = ceil;
//    while( ceil = strtok(NULL, split) ) {
//        array[key] = (char *)malloc( (strlen(ceil) + 1)*sizeof(char) );
//        array[key++] = ceil;
//    }
////    printf(">%s\n", array[1]);
//    result = array;
////    printf(">%s\n", result[1]);
//    return result;
}

char * sstrtok( char *s1, const char *s2 )
{
    char *sbegin, *send;
    static char *ssave = "";

    sbegin = s1 ? s1 : ssave;
    sbegin += strspn( sbegin, s2 );
    if ( *sbegin == '\0' ) {
        ssave = "";
        return (NULL);
    }
    send = sbegin + strcspn( sbegin, s2 );
//    puts(send);
    if( *send != '\0' )
        *send++ = '\0';
    ssave = send;
    return (sbegin);

}

char * strntok( char *dest, char *s1, const int step )
{
    static char *ssave = "";
    static int p_step = 0;
    char *sbegin, *send;

    //源字符串定位
//printf( "--%p->%p\n", dest, ssave );
    sbegin = s1 ? s1 : ssave;
    if( *sbegin == '\0' ) {
        ssave = "";
        return ssave;
    }

    //确定源字符串，目标字符串位置
    dest += p_step + 1;
    int i;
    for( i=0; i<step; i++ ) {
        dest[i] = sbegin[i];
    }
    dest[i] = '\0';
    p_step += i + 1;
    send = sbegin + i;
    ssave = send;
    return dest;
}

int main()
{
//调用 sstrtok 方法
//    char time[30] = "2017-03-01";
//    char s[2] = "-";
//    char *token;
//    token = sstrtok( time, s );
//    puts(token);
//    token = sstrtok( NULL, s );
//    puts(token);
//    exit(0);

//调用strntok方法
//    char time[30] = "20170301";
//    char dest[30];
//    char *token;
//    token = strntok( dest, time, 4 );
//    puts(token);
//    printf( "%p\n", token );
//    token = strntok( dest, NULL, 2 );
//    puts(token);
//    printf( "%p\n", token );
//    token = strntok( dest, NULL, 2 );
//    puts(token);
//    printf( "%p\n", token );
//    exit(0);

//日期输出格式
//char head[3] = "AA";
//char *data[9] = {"a1", "a2", "a3", "a4", "a5", "a6", "a7", "a8", "a9"};
//char cals[1024];
//int i,j,k;
//int num = 8;
//int col = 3;
//int col_p;
//
//for( i=0; i<(num/3+1); i++ ) {
//    col_p = num>col*i?col:(num-col*i);
//    for( j=0; j<col_p; j++ ) {
//        sprintf( cals, "%s %s  ", cals, head );
//    }
//    sprintf( cals, "%s\n", cals );
//    col_p = num>col*(i+1)? col*(i+1) : num;
//    for( j=(col*i); j<col_p; j++ ) {
//        sprintf( cals, "%s %s  ", cals, data[j] );
//    }
//    sprintf( cals, "%s\n", cals );
//}
//printf("%s\n", cals);




//日期输出格式-2
//char const *data4[3][3] = {"a1", "a2", "a3", "a4", "a5", "a6", "a7", "a8", "a9"};
//
//printf( "%s\n", data4[1][1] );
//exit(0);

//char const *data1[9] = {"a1", "a2", "a3", "a4", "a5", "a6", "a7", "a8", "a9"};
//char const *data2[9] = {"b1", "b2", "b3", "b4", "b5", "b6", "b7", "b8", "b9"};
//
//char const **data3[2] = { data1, data2 };
//printf( "%s\n", data3[1][0] );
//exit(0);


char head[3] = "AA";
const char *data0[10] = {"a1", "a2", "a3", "a4", "a5", "a6"};
const char *data1[10] = {"b1", "b2", "b3", "b4", "b5", "b6"};
const char *data2[10] = {"c1", "c2", "c3", "c4", "c5", "c6"};
const char *data3[10] = {"d1", "d2", "d3", "d4", "d5", "d6"};
const char *data4[10] = {"e1", "e2", "e3", "e4", "e5", "e6"};
const char *data5[10] = {"f1", "f2", "f3", "f4", "f5", "f6"};
const char **data[7] = { data0, data1, data2, data3, data4, data5 };
char cals[1024];
int col = 3;
int i,j,k;
int sstart, is_over;


i=0;
j=0;
while( data[i] != NULL ) {
    //添加日历头
    sprintf( cals, "%s %s  ", cals, head );

    if( (i+1)%col == 0 || data[i+1] == NULL )
        sprintf( cals, "%s\n", cals );

    //生成日历数据 
    if( (i+1)%col == 0 || data[i+1] == NULL ) {
        sstart = (i+1)-col;
        k=0;
        while( 1 ) {
            is_over = 0;
            for( j=sstart; j<(sstart+col); j++ ) {
                is_over = is_over || data[j][k];
                if( data[j][k]==NULL ) {
                    sprintf( cals, "%s   ", cals );
                } else {
                    sprintf( cals, "%s %s  ", cals, data[j][k] );
                }
            }
            sprintf( cals, "%s \n", cals );
            if( is_over==0 ) {
                break;
            }
            k++;
        }
    }
    i++;
}
printf( "%s\n", cals );
exit(0);


//for( i=0; i<(num/3+1); i++ ) {
//    col_p = num>col*i?col:(num-col*i);
//    for( j=0; j<col_p; j++ ) {
//        sprintf( cals, "%s %s  ", cals, head );
//    }
//    sprintf( cals, "%s\n", cals );
////    col_p = num>col*(i+1)? col*(i+1) : num;
////    for( j=(col*i); j<col_p; j++ ) {
//    for( j=0; j<row; j++ ) {
//        for( k=0; k<row; k++ ) {
//            sprintf( cals, "%s %s ", cals, data[k][j] );
//        }
//        sprintf( cals, "%s\n", cals );
//    }
//    sprintf( cals, "%s\n", cals );
//}
//printf("%s\n", cals);


//    char input[30]="hello,world,c language";
//    char **array;
//    array = explode( input, "," );
//    printf("%s\n", array[0]);
//    printf(">>%s\n", array[1]);
//    printf("%s\n", array[2]);

//    char *str;
//    str = getStr();
//    printf("%s\n", str);

//    char *output = strtok(input, ",");
//    printf("%s<<\n", output);
//    output = strtok(NULL, ",");
//    printf("%s<<\n", output);
return 0;
}
