#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#ifndef  TOOL_H
#include "../include/tool.h"
#endif

#define LEAP_YEAR_DAYS 366 
#define NORMAL_YEAR_DAYS 365 



int isLeapYear( int year );
int getMonthDays( int year, int month );
int calcPastDays( int year, int month, int day );
int calcResetDays( int year, int month, int day );
int calculateDays( int ys, int ms, int ds, int yp, int mp, int dp );
int calculateYearsDays( int ys, int yp );
int getYearDays( int year );
char *weekToEn( int week, char *week_en );
char *monthToEn( int month, char *month_en );
char *weekHead( int monday_first, char *interval, char *week_head );
int getWeekDay( int year, int month, int day );
char *mkCals( int year, int month, int day, int monday_first );
/**
 * @note 是否为闰年
 */
int isLeapYear( int year )
{
    if( (year%4==0 && year%100!=0) || (year%400==0) ) {
        return 1;
    }
    return 0;
}

/**
 * @note 获取指定月份天数
 */
int getMonthDays( int year, int month )
{
    int month_days = 0;
    int is_leap_year;
    switch( month )
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            month_days = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            month_days = 30;
            break;
        case 2:
            is_leap_year = isLeapYear( year );
            month_days = is_leap_year ? 29 :28;
            break;
    }
    return month_days;
}

/**
 * @note 求当前日期已过天数
 */
int calcPastDays( int year, int month, int day )
{
    int month_point;
    int days = 0;
    int current_month_days = getMonthDays( year, month );
    if( day > current_month_days ) return 0;

    days += day;
    for( month_point = 1; month_point < month; month_point++ ){
        days += getMonthDays( year, month_point );
    }
    return days;
}

/**
 * @note 求当前日期还剩天数
 */
int calcResetDays( int year, int month, int day )
{
    int month_point;
    int days = 0;
    int current_month_days = getMonthDays( year, month );

    if( day > current_month_days ) return 0;

    days += current_month_days - day;
    for( month_point = 12; month_point > month; month_point-- ){
        days += getMonthDays( year, month_point );
    }
    return days;
}

/**
 * @note 两日期之前相差天数
 */
int calculateDays( int ys, int ms, int ds, int yp, int mp, int dp )
{
    int days = 0;
    days += calcPastDays( yp, mp, dp );
    days += calculateYearsDays( ys, yp );
    days -= calcPastDays( ys, ms, ds );
    return days;
}

/**
 * @note 从第X年初到第Y年末经历的天数
 */
int calculateYearsDays( int ys, int yp )
{
    if( yp <= ys ) return 0;
    int year_point = 0;
    int days = 0;
    for( year_point = ys; yp>year_point; year_point++ ) {
        days += isLeapYear( year_point ) ? LEAP_YEAR_DAYS : NORMAL_YEAR_DAYS;
    }
    return days;
}


/**
 * @note 获取指定月份天数
 */
int getYearDays( int year )
{
    int is_leap_year = isLeapYear( year );
    return is_leap_year ? LEAP_YEAR_DAYS : NORMAL_YEAR_DAYS;
}

/**
 *  @note  获取周英文
 *  week=0, 返回周一
 */
char *weekToEn( int week, char *week_en ) 
{
    const char* week_list[] = {"Mo", "Tu", "We", "Th", "Fr", "Sa", "Su"};
    if( week >= 0 && week < 7 ) {
        strcpy( week_en, week_list[week] );
        return week_en;
    } 
    return '\0';
}
/**
 *  @note  获取月份英文
 *  month=0, 返回一月
 */
char *monthToEn( int month, char *month_en ) 
{
    const char* month_list[] = {
        "January","February","March","April","May","June"
        ,"July","August","September","October","November","December" 
    };
    if( month >= 0 && month < 12 ) {
        strcpy( month_en, month_list[month] );
        return month_en;
    } 
    return '\0';
}

/**
 * @note 计量指定日期为周几
 */
int getWeekDay( int year, int month, int day )
{
    int days;
    int weekday = 0;
    if( year > 1977 ) {
        days = calculateDays( 1977, 3, 27, year, month, day );
        weekday = days%7;
    } else {
        days = calculateDays( year, month, day, 1977, 3, 27 );
        weekday = 7-days%7;
    }
//printf( "相距天数 : %d\n", days );
    return weekday;
}


/**
 * @note 返回日历周头
 * weekHead( 1, " ", week_head );
 */
char *weekHead( int monday_first, char *interval, char *week_head )
{
    const char *calc_head[] = {"Mo", "Tu", "We", "Th", "Fr", "Sa", "Su"};
    int i;

    if( monday_first != 1 ) { 
        sprintf( week_head, "%s%s%s", week_head, interval, calc_head[6] );
    }
    for( i=0; i<6; i++ ) {
        sprintf( week_head, "%s%s%s", week_head, interval, calc_head[i] );
    }
    if( monday_first == 1 ) { 
        sprintf( week_head, "%s%s%s", week_head, interval, calc_head[6] );
    }
    return week_head;
}


/**
 * @note 生成显示列表
 * @type y:显示年，q:显示季度, t:最近月份(前一月，当前，后一月), m:当前月份
 */
char *mkCals( int year, int month, int day, int monday_first, char type )
{
    char cals_out[2048];

    
}


/**
 * @note 生成显示内容
 */
void printCalc( int year, int month, int day, int is_monday_ahead )
{
    const char* calc_head[] = {"Mo", "Tu", "We", "Th", "Fr", "Sa", "Su"};
    const char* calc_head_2[] = {"Su", "Mo", "Tu", "We", "Th", "Fr", "Sa"};
    char month_out[1204];
    int i=0;
    for( i=0; i<7; i++ ) {
        strcat( month_out, " " );
        if( is_monday_ahead == 1 ) 
            strcat( month_out, calc_head[i] );
        else 
            strcat( month_out, calc_head_2[i] );
    }
    strcat( month_out, "\n" );
    int week_day = getWeekDay( year, month, day );
    int month_start_day = is_monday_ahead ? week_day - 1 : week_day;
    int month_days = getMonthDays( year, month );
    int month_day_point = 0;
    month_start_day = month_start_day >= 6 ? month_start_day - 7 : month_start_day;

    for( i = 0; i <= month_start_day+month_days; i++ ) {
        if( i <= month_start_day ) {
            strcat( month_out, "  -" );
        } else {
            month_day_point = i - month_start_day;

            if( month_day_point < 10 ) 
                sprintf( month_out, "%s  ", month_out );
            else 
                sprintf( month_out, "%s ", month_out );

            if( month_day_point == day )
                sprintf( month_out, "%s\033[43m\033[31m\033[01m\033[05m%d\033[0m", month_out,  month_day_point );
            else
                sprintf( month_out, "%s%d", month_out, month_day_point );
        }

        if( i % 7 == 6 ) {
            strcat( month_out, "\n" );
        }
    }
    printf( "%s\n", month_out );
//    exit(0);
}

//int main( int argx, char *date[] )
int main ( int argc, char *argv[] )
{
    //分析输入
//    char month_en[10];
//    printf( "%d, %s\n", argc, monthToEn( atoi(argv[1]), month_en ) );
//    exit( 0 );

    char date[20];
    char *dates[4];
    strcpy( date, argv[1] );

//    strcpy( date, "2017-09-11" );
//    strcpy( date, "2017/09/11" );
//    strcpy( date, "20170911" );
//    getDateMode(date);
    analyzeDateFormat( date, dates );


    // 返回周几
    printCalc( atoi(dates[0]), atoi(dates[1]), atoi(dates[2]), 1 );
//    printCalc( 2018, 3, 0, 1 );
    return 0;
}
