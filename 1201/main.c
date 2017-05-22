#include <stdio.h>
#include <string.h>
#include <time.h>
#define MAXSIZE 101

typedef struct Date
{
    int year;
    int month;
    int day;
}Date;
Date nowDate();
Date strToDate( char[]);
int illegalAge( int *birthday );
int ctoi( char X);

int main() {
    Date currentDate;
    int instance;
    char inputDate[20];
    scanf("%d",&instance);
    if( getchar() == '\n')
    {
        while( instance-- )
        {
            gets(inputDate);
            strToDate(inputDate);
            puts(inputDate);
        }

        currentDate = nowDate();
        printf("%d  %d  %d\n",currentDate.year,currentDate.month,currentDate.day);

    }
    return 0;
}

Date nowDate()
{
    time_t rawtime;
    struct tm *timeinfo;
    char buffer[100];
    Date currentDate;

    time( &rawtime );
    timeinfo = localtime( &rawtime );
    strftime( buffer,sizeof( buffer ),"%Y-%m-%d",timeinfo );

    currentDate.year = ctoi(buffer[0])*10*10*10 + ctoi(buffer[1])*10*10 + ctoi(buffer[2])*10 + ctoi(buffer[3]);
    currentDate.month = ctoi(buffer[5])*10 + ctoi(buffer[6]);
    currentDate.day = ctoi(buffer[8])*10 + ctoi(buffer[9]);

    return currentDate;
}

Date strToDate( char a[MAXSIZE])
{
    Date date;
    char year[5], month[3], day[3];
    char *ptrToYear, *ptrToMonth, *ptrToDay, *ptrToChar;

    ptrToYear = year;
    ptrToMonth = month;
    ptrToYear = day;
    ptrToChar = a;

    while( *ptrToChar != '\0')
    {
        if( *ptrToYear != '\0')
        {
            if( *ptrToChar != '-')
            {
                *ptrToYear = *ptrToChar;
            }
            else
            {
                *ptrToYear = '\0';
            }
            ptrToYear++;
            ptrToChar++;
        }

        if( *ptrToMonth != '\0')
        {
            if( *ptrToChar != '-')
            {
                *ptrToMonth = *ptrToChar;
            }
            else
            {
                *ptrToMonth = '\0';
            }
            ptrToMonth++;
            ptrToChar++;
        }

        if( *ptrToDay != '\0')
        {
            if( *ptrToChar != '-')
            {
                *ptrToDay = *ptrToChar;
            }
            else
            {
                *ptrToDay = '\0';
            }
            ptrToDay++;
            ptrToChar++;
        }
    }

    puts(year);
    puts(month);
    puts(day);

    return date;
}

int ctoi( char X)
{
    if( X >= '0' && X <= '9')
        return X-48;
}