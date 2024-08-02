#include <iostream>
#include <algorithm>
using namespace std;
struct process
{
    char process_name;
    int burst_time;
    int arrival_time;
    int response_time = 0;
    int completion_time = 0;
    int waiting_time = 0;
} a[100], b[100], c[100];
bool btimeSort(process a, process b)
{
    return a.burst_time < b.burst_time;
}
bool atimeSort(process a, process b)
{
    return a.arrival_time < b.arrival_time;
}
int k = 0, f = 0, r = 0;
void display(int m, int current_time)
{
    int n = m, q;
    sort(a, a + n, atimeSort);
    int total_time = 0, i;
    int j, total_array[n];
    int alltime = 0;
    bool counter = false;
    for (i = 0; i < n; i++)
    {
        alltime += a[i].burst_time;
    }
    alltime += a[0].arrival_time;
    for (i = 0; total_time <= alltime;)
    {
        j = i;
        while (a[j].arrival_time <= total_time && j != n)
        {
            b[r] = a[j];
            j++;
            r++;
        }
        if (r == f)
        {
            c[k].process_name = 'i';
            c[k].burst_time = a[j].arrival_time;
            c[k].arrival_time = total_time;
            total_time += c[k].burst_time;
            k++;
            continue;
        }
        i = j;
        if (counter == true)
        {
            sort(b + f, b + r, btimeSort);
        }
        j = f;
        if (b[j].burst_time > current_time)
        {
            c[k] = b[j];
            c[k].burst_time = current_time;
            k++;
            b[j].burst_time = b[j].burst_time - current_time;
            total_time += current_time;
            counter = true;
            for (q = 0; q < n; q++)
            {
                if (b[j].process_name != a[q].process_name)
                {
                    a[q].waiting_time += current_time;
                }
            }
        }
        else
        {
            c[k] = b[j];
            k++;
            f++;
            total_time += b[j].burst_time;
            counter = false;
            for (q = 0; q < n; q++)
            {
                if (b[j].process_name != a[q].process_name)
                {
                    a[q].waiting_time += b[j].burst_time;
                }
            }
        }
        if (f == r && i >= n)
            break;
    }
    total_array[i] = total_time;
    total_time += a[i].burst_time;
    for (i = 0; i < k - 1; i++)
    {
        if (c[i].process_name == c[i + 1].process_name)
        {
            c[i].burst_time += c[i + 1].burst_time;
            for (j = i + 1; j < k - 1; j++)
                c[j] = c[j + 1];
            k--;
            i--;
        }
    }
    int rtime = 0;
    for (j = 0; j < n; j++)
    {
        rtime = 0;
        for (i = 0; i < k; i++)
        {
            if (c[i].process_name == a[j].process_name)
            {
                a[j].response_time = rtime;
                break;
            }
            rtime += c[i].burst_time;
        }
    }

    rtime = 0;
    for (i = 0; i < k; i++)
    {
        if (i != k)

            rtime += c[i].burst_time;
        for (j = 0; j < n; j++)
        {
            if (a[j].process_name == c[i].process_name)
                a[j].completion_time = rtime;
        }
    }

    rtime = 0;
    for (i = 0; i < k + 1; i++)
    {
        // cout << rtime << "\t";
        total_array[i] = rtime;
        rtime += c[i].burst_time;
    }
    float averageWaitingTime = 0, averageResponseTime = 0, averageTAT = 0, averagect = 0;
    cout << "\nGantt Chart\n ";
    rtime = 0;
    for (i = 0; i < k; i++)
    {
        if (i != k)
            cout << "| " << 'P' << c[i].process_name << " ";
        rtime += c[i].burst_time;
        for (j = 0; j < n; j++)
        {
            if (a[j].process_name == c[i].process_name)
                a[j].completion_time = rtime;
        }
    }
    printf("\n\n");
    cout << "P.Name AT\tBT\tCT\tTAT\tWT\tRT\n";
    for (i = 0; i < m && a[i].process_name != 'i'; i++)
    {
        if (a[i].process_name == '\0')
            break;
        cout << 'P' << a[i].process_name << "\t";
        cout << a[i].arrival_time << "\t";
        cout << a[i].burst_time << "\t";
        cout << a[i].completion_time << "\t";
        cout << a[i].completion_time - a[i].arrival_time<< "\t";
        averageTAT += a[i].completion_time - a[i].arrival_time;
        cout << a[i].waiting_time + a[i].completion_time - rtime << "\t";
        averageWaitingTime += a[i].waiting_time + a[i].completion_time - rtime;
        cout << a[i].response_time << "\t";
        averageResponseTime += a[i].response_time;
        cout << "\n";
    }
    for (int i = 0; i < m; i++)
    {
        averagect += a[i].completion_time;
    }
    cout << "Average Completion Time " << (float)averagect / (float)n << endl;
    cout << "Average TA time: " << (float)averageTAT / (float)n << endl;
    cout << "Average Waiting time: " << (float)averageWaitingTime / (float)n << endl;
    cout << "Average Response time: " << (float)averageResponseTime / (float)n << endl;
}
int main()
{
    int m, choice, i, current_time;
    cout << "\nBushra Shahzad-21BCS046\n";
    cout << "Enter number of processes: ";
    cin >> m;
    cout << "Enter process, arrival time, Burst Time!\n";
    for (i = 0; i < m; i++)
    {
        cout << "Enter process id: ";
        cin >> a[i].process_name;
        cout << "Enter arrival time: ";
        cin >> a[i].arrival_time;
        cout << "Enter burst time: ";
        cin >> a[i].burst_time;
        a[i].waiting_time = -a[i].arrival_time + 1;
    }
    display(m, 1);
    return 0;
}
