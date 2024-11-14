#include <stdio.h>
#include <time.h>

int main(int argc,char *argv[]){
    time_t now;
    time(&now);
    int year,month,day;
    scanf("%d %d %d",&year, &month, &day);
    struct tm from=*localtime(&now);
    from.tm_hour=0;
    from.tm_min=0;
    from.tm_sec=0;
    from.tm_mon=month-1;
    from.tm_mday=day;
    from.tm_year=year-1900;
    double dayperseconds=60*60*24;
    double seconds=difftime(mktime(&from),now);
    char *before_after="후";
    if(seconds<0){
        seconds*=-1;
        before_after="전";
    }
    printf("%d년 %d월 %d일은 오늘로부터 %d일 %s입니다.",year, month, day,(int)(seconds/dayperseconds),before_after);
    return 0;
}