#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
struct node
{
    int id;
    int arrival_time;
    int burst_time;
    int completion_time;
    int waiting_time;
    int turn_around_time;
    int st;
} p[100];
int main()
{
    printf("\nBushra Shahzad-21BCS046\n");
    int n, t, current_time = 0;
    int proecess_executed[20] = {0};
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    t = n;
    float atat = 0, awt = 0, act = 0;
    for (int i = 0; i < n; i++)
    {
        printf("P%d : ", i + 1);

        printf("\nBurst time : ");
        scanf("%d", &p[i].burst_time);
        printf("Arrival time : ");
        scanf("%d", &p[i].arrival_time);
        p[i].id = i + 1;
    }
    while (t)
    {
        int min_index = -1;
        int min_burst_time = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (p[i].arrival_time <= current_time && proecess_executed[i] == 0)
            {
                if (p[i].burst_time < min_burst_time)
                {
                    min_burst_time = p[i].burst_time;
                    min_index = i;
                }
                if (p[i].burst_time == min_burst_time)
                {
                    if (p[i].arrival_time < p[min_index].arrival_time)
                    {
                        min_burst_time = p[i].burst_time;
                        min_index = i;
                    }
                }
            }
        }
        if (min_index == -1)
        {
            current_time++;
        }
        else
        {
            p[min_index].st = current_time;
            p[min_index].completion_time = p[min_index].st + p[min_index].burst_time;
            p[min_index].turn_around_time = p[min_index].completion_time - p[min_index].arrival_time;
            p[min_index].waiting_time = p[min_index].turn_around_time - p[min_index].burst_time;
            atat += p[min_index].turn_around_time;
            awt += p[min_index].waiting_time;
            act += p[min_index].completion_time;
            proecess_executed[min_index] = 1;
            current_time = p[min_index].completion_time;
            t--;
        }
    }

    printf("\nProcess No.\tBT\tAT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].burst_time, p[i].arrival_time, p[i].completion_time, p[i].turn_around_time, p[i].waiting_time);
    printf("\n");
    printf("\nAverage Turn Around Time = %0.2f", atat / n);
    printf("\nAverage Waiting Time = %0.2f ", awt / n);
    printf("\nAverage Completion Time = %0.2f", act / n);

    return 0;
}