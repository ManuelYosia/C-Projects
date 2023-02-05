#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

int main()
{
    int h, m, s; //hours, minutes, seconds
    int delay = 1000; //delay 1000ms

    puts("Set time!");
    scanf("%d%d%d", &h, &m, &s); //set time

    if(h > 12 || m > 60 || s > 60) 
    {
        puts("Error!!");
        exit(0);
    }

    while(1)
    {   
        s++;
        if(s > 59) 
        {
            m++;
            s = 0;
        }
        if(m > 59)
        {
            h++;
            m = 0;
        }
        if(h > 12)
        {
            h = 1;
        }

        printf("\nClock:"); 
        printf("\n%02d:%02d:%02d", h, m, s);
        Sleep(delay);
        system("cls");
    }

    return 0;
}
