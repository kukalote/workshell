#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_COLS 4
#define MAX_INPUT 1000

int read_column_numbers( int columns[], int max );
void rearrange( char *output, char const *input,
    int n_columns, int const columns[] );

int main( void )
{
    int n_columns;
    int columns[MAX_COLS];
    char input[MAX_INPUT];
    char output[MAX_INPUT];

    n_columns = read_column_numbers( columns, MAX_COLS );

    while( fgets( input, sizeof(input), stdin ) != NULL ){
        printf( "Original input : %s\n", input );
        rearrange( output, input, n_columns, columns );
        printf( "Rearranged line : %s\n", output );
    }
    return EXIT_SUCCESS;
}

int read_column_numbers( int columns[], int max )
{
    int num = 0;
    int ch;

    while( num < max && scanf( "%d", &columns[num] ) == 1
        && columns[num] >= 0 )
        num += 1;

    if( num % 2 != 0 ) {
        puts( "Last column number is not paired." );
        exit( EXIT_FAILURE ); 
    }

    //scanf 只读取需要的数据，如果仍留有换行符等符号，可
    //能误被当作第一行处理,这里将剩余字符取出
    while( (ch = getchar()) != EOF && ch != '\n' )
        ;
    return num;
}
/**
 * output 空字符串
 * input  二次输入
 * n_columns  一次输入行数
 * columns    输入内容(数组)
 *
 */
void rearrange( char *output, char const *input,
    int n_columns, int const columns[] )
{
    int col;
    int output_col;
    int len;

    len = strlen( input );
    output_col = 0;

    /**
     * 处理每对列标号
     */
    for( col = 0; col < n_columns; col += 2 ) {
        int nchars = columns[col + 1] - columns[col] + 1;

        /**
         * 如果输入行结束或输出行数组已满，就结束任务
         */
        if( columns[col] >= len ||
            output_col == MAX_INPUT - 1 )
            break;

        /**
         * 如果输出行数据空间不够，只复制可以容纳的数据
         */
        if( output_col + nchars > MAX_INPUT -1 )
            nchars = MAX_INPUT - output_col - 1;

        /**
         * 复制相关的数据
         */
        strncpy( output + output_col, input + columns[col], 
            nchars );
        output_col += nchars;
    }
    output[output_col] = '\0';
}


