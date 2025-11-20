#include <stdio.h>

int main()
{
    int f, p;
    int pages[50], frame[10], hit = 0, count[50], time[50];
    int i, j, page, flag, least, minTime, temp = 0;

    printf("Enter no of frames : ");
    scanf("%d", &f);

    printf("Enter no of pages : ");
    scanf("%d", &p);

    
    for(i = 0; i < f; i++)
        frame[i] = -1;

    
    for(i = 0; i < 50; i++) {
        count[i] = 0;
        time[i] = -1;
    }

    printf("Enter page numbers:\n");
    for(i = 0; i < p; i++)
        scanf("%d", &pages[i]);

    printf("\n");

    for(i = 0; i < p; i++)
    {
        page = pages[i];
        count[page]++;         
        time[page] = i;        
        flag = 1;

        least = frame[0];      

        
        for(j = 0; j < f; j++)
        {
            if(frame[j] == -1 || frame[j] == page)
            {
                
                if(frame[j] == page)
                    hit++;

                frame[j] = page;
                flag = 0;
                break;
            }

            
            if(count[least] > count[frame[j]])
                least = frame[j];
        }

        
        if(flag)
        {
            minTime = 999;

            
            for(j = 0; j < f; j++)
            {
                if(count[frame[j]] == count[least] && time[frame[j]] < minTime)
                {
                    temp = j;
                    minTime = time[frame[j]];
                }
            }

            
            count[frame[temp]] = 0;

            
            frame[temp] = page;
        }

        
        for(j = 0; j < f; j++)
            printf("%d ", frame[j]);

        printf("\n");
    }

    printf("Page hit = %d\n", hit);
    printf("Page faults = %d\n", p - hit);

    return 0;
}