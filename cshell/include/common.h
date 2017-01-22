unsigned long GetTick(int iY,int iM,int iD,int iH,int iMin,int iS);

//char * getRealString( char * option );
//int getStringNum( char *str_array, int judge_new_line );

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


int getRealStringNum( char *str_array, int judge_new_line ) 
{
    int i = 0;
    while ( str_array[i] != EOF && str_array[i] ) {
        if( judge_new_line==1 && str_array[i] == '\n' ) {
            break;
        }
        i++;
    }
    return i;
}
char *getRealString( char * option ) 
{
    int i;
    int option_num;
    option_num = getRealStringNum( option, 1 );
    char *option_bak = malloc( option_num );
    strncpy( option_bak, option, option_num );
    return (option_bak);
}


char * getOption( void ) 
{
    char option[255];
    int option_num = 0;
    fgets( option, 1024, stdin );
    return getRealString( option );
}
