#include <iolib.h>

int main( int argc, char ** date )
{
    int year=0, month=0, day=0, week;
    int d, i, dm, dy, m2;
    char WEEK[9];
    if(x==1) {
        printf("\n ERROR! you forget enter the date you want to view\n");
        exit(0);
    }
    i=0; d=-1;
    while( date[1][i] ) {
        if( (date[1][i]=='/' || date[1][i]=='.' ) && d==-1 ) { d=0; i++; continue; }
        if( (date[1][i]=='/' || date[1][i]=='.' ) && d==0 ) { d=1; i++; continue; }
        if( d==-1 ) year = year * 10 + ( date[1][i] - '0' );
        if( d==0 ) month = month * 10 + ( date[1][i] - '0' );
        if( d==1 ) day = day * 10 + ( date[1][i] - '0' );
        i++;
    }
    //判断闰年方法
    if( (year%4==0 && year%100==0) || (year%100==0 && year%400==0) ) {

    }

}
