#include <stdio.h>

int main()
{
    int time,duration,end_time;
    printf("./time\n");
    printf("Enter the start time: ");
    scanf("%d",&time);
    printf("Enter the duration: ");
    scanf("%d",&duration);

    int a = duration/60;
    int c = time + (a*100) + (duration%60);
    int b = c/2400;
    int d = c - b*2400;

    if((d % 100) >= 60)
    {
        end_time = d - 60 + 100;

    }
    else
    {
        end_time=d;

    }

    if(end_time == 2400)
    {
        printf("End time is 0000.\n");

    }
    else
    {
        printf("End time is %d.\n",end_time);

    }

    return 0;
}
