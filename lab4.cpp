#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;
struct node
{
    char pname;
    int burst_time;
    int arrival_time;
    int response_time = 0;
    int completion_time = 0;
    int waiting_time = -1;
} a[100], b[100], c[100];
bool btimeSort(node a, node b)
{
    return a.burst_time < b.burst_time;
}
bool atimeSort(node a, node b)
{
    return a.arrival_time < b.arrival_time;
}
int k = 0, f = 0, r = 0;
void disp(int nop, int qt)
{
    int n = nop, q;
    sort(a, a + n, atimeSort);
    int ttime = 0, i;
    int j, tArray[n];
    int alltime = 0;
    bool moveLast = false;
    for (i = 0; i < n; i++)
    {
        alltime += a[i].burst_time;
    }
    alltime += a[0].arrival_time;
    for (i = 0; ttime <= alltime;)
    {
        j = i;
        while (a[j].arrival_time <= ttime && j != n)
        {
            b[r] = a[j];
            j++;
            r++;
        }
        if (r == f)
        {
            c[k].pname = 'i';
            c[k].burst_time = a[j].arrival_time - ttime;
            c[k].arrival_time = ttime;
            ttime += c[k].burst_time;
            k++;
            continue;
        }
        i = j;
        if (moveLast == true)
        {
            b[r] = b[f];
            f++;
            r++;
        }
        j = f;
        if (b[j].burst_time > qt)
        {
            c[k] = b[j];
            c[k].burst_time = qt;
            k++;
            b[j].burst_time = b[j].burst_time - qt;
            ttime += qt;
            moveLast = true;
            for (q = 0; q < n; q++)
            {
                if (b[j].pname != a[q].pname)
                {
                    a[q].waiting_time += qt;
                }
            }
        }
        else
        {
            c[k] = b[j];
            k++;
            f++;
            ttime += b[j].burst_time;
            moveLast = false;
            for (q = 0; q < n; q++)
            {
                if (b[j].pname != a[q].pname)
                {
                    a[q].waiting_time += b[j].burst_time;
                }
            }
        }
        if (f == r && i >= n)
            break;
    }
    tArray[i] = ttime;
    ttime += a[i].burst_time;
    int rtime = 0;
    for (j = 0; j < n && j < 6; j++)
    {
        rtime = 0;
        for (i = 0; i < k; i++)
        {
            if (c[i].pname == a[j].pname)
            {
                a[j].response_time = rtime;
                break;
            }
            rtime += c[i].burst_time;
        }
    }
    float averageWaitingTime = 0;
    float averageResponseTime = 0;
    float averageTAT = 0;
    float averageCT=0;
    printf("\nGantt Chart\n");
    rtime = 0;
    for (i = 0; i < k + 1 && i < 20; i++)
    {
        if (i != k)
            printf("| %c ", c[i].pname);
       
        rtime += c[i].burst_time;
        for (j = 0; j < 6; j++)
        {
            if (a[j].pname == c[i].pname)
                a[j].completion_time = rtime;
        }
    }
    printf("\n");
    rtime = 0;
    for (i = 0; i < k + 1 && i < 20; i++)
    {
        
        printf(" %d ", rtime);
        tArray[i] = rtime;
        rtime += c[i].burst_time;
    }
    printf("\n");
    printf("\n");

    printf("P.Name AT\tBT\tCT\tTAT\tWT\tRT\n");
    for (i = 0; i < 6 && i < nop && a[i].pname != 'i'; i++)
    {
        if (a[i].pname == '\0')
            break;

        printf("%d\t", a[i].pname);
        printf("%d\t", a[i].arrival_time);
        printf("%d\t", a[i].burst_time);
        printf("%d\t", a[i].completion_time);
        averageCT+=a[i].completion_time;
        printf("%d\t", a[i].waiting_time + a[i].completion_time - rtime + a[i].burst_time);
        averageTAT += a[i].waiting_time + a[i].completion_time - rtime + a[i].burst_time;
        printf("%d\t", a[i].waiting_time + a[i].completion_time - rtime);
        averageWaitingTime += a[i].waiting_time + a[i].completion_time - rtime;
        printf("%d", a[i].response_time);
        averageResponseTime += a[i].response_time;
        printf("\n");
    }
    cout << "\nAverage Completion time: " << (float)averageCT / (float)n << endl;
    cout << "\nAverage TurnAround time: " << (float)averageTAT / (float)n << endl;
    cout << "Average Waiting time: " << (float)averageWaitingTime / (float)n << endl;
    cout << "Average Response time: " << (float)averageResponseTime / (float)n << endl;
}
int main()
{
    int n, qt;
    printf("\nBushra Shahzad-21BCS046\n");
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter time quantum: ");
    scanf("%d", &qt);
    printf("\nEnter the process\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter process id: ");
        cin >> a[i].pname;
        printf("Enter arrival time: ");
        scanf("%d", &a[i].arrival_time);
        printf("Enter burst time: ");
        scanf("%d", &a[i].burst_time);
        a[i].waiting_time = -a[i].arrival_time;
    }
    disp(n, qt);
    return 0;
}
