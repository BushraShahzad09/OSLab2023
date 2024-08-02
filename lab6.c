#include <stdio.h>
#include <stdlib.h>
void fcfs(int *a, int n)
{
    int curr = 53, headmov = 0;
    printf("\nSeek sequence :\n");
    for (int i = 0; i <= n; i++)
    {
        printf("%d -> ", curr);
        if (i != n)
            headmov += abs(*(a + i) - curr);
        curr = *(a + i);
    }
    printf("\nTotal head movements : %d", headmov);
}
void sstf(int *a, int n)
{
    int temp[n], i, headmov = 0, j, k, curr = 53, b;
    char dir = 'L';
    for (i = 0; i < n; i++)
    {
        temp[i] = *(a + i);
    }
    // Sorting
    for (i = 0; i < n; ++i)
    {

        for (j = i + 1; j < n; ++j)
        {

            if (temp[i] > temp[j])
            {

                b = temp[i];
                temp[i] = temp[j];
                temp[j] = b;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (temp[i] > 53)
        {
            j = i;
            k = i - 1;
            break;
        }
        else if (temp[i] == 53)
        {
            j = i + 1;
            k = i - 1;
            break;
        }
    }
    printf("\nSeek Sequence:\n53 -> ");
    while (k >= 0 || j < n)
    {
        if (k >= 0 && j < n)
        {
            if (abs(curr - temp[j]) > abs(curr - temp[k]))
            {
                headmov += abs(curr - temp[k]);
                curr = temp[k];
                k = k - 1;
                dir = 'L';
                printf("%d -> ", curr);
            }
            else if (abs(curr - temp[j]) < abs(curr - temp[k]))
            {
                headmov += abs(curr - temp[j]);
                curr = temp[j];
                j = j + 1;
                dir = 'R';
                printf("%d -> ", curr);
            }
            else
            {
                if (dir == 'L')
                {
                    headmov += abs(curr - temp[k]);
                    curr = temp[k];
                    k = k - 1;
                    dir = 'L';
                    printf("%d -> ", curr);
                }
                else
                {
                    headmov += abs(curr - temp[k]);
                    curr = temp[k];
                    k = k - 1;
                    dir = 'R';
                    printf("%d -> ", curr);
                }
            }
        }
        else if (k < 0 && j < n)
        {
            headmov += abs(curr - temp[j]);
            curr = temp[j];
            j = j + 1;
            dir = 'R';
            printf("%d -> ", curr);
        }
        else if (k >= 0 && j >= n)
        {
            headmov += abs(curr - temp[k]);
            curr = temp[k];
            k = k - 1;
            dir = 'L';
            printf("%d -> ", curr);
        }
    }
    printf("\nTotal head movements : = %d", headmov);
}
void scan(int *a, int n)
{
    int temp[n], i, headmov = 0, j, k, curr = 53, b;
    char dir = 'L';
    for (i = 0; i < n; i++)
    {

        temp[i] = *(a + i);
    }
    // sorting
    for (i = 0; i < n; ++i)
    {

        for (j = i + 1; j < n; ++j)
        {

            if (temp[i] > temp[j])
            {

                b = temp[i];
                temp[i] = temp[j];
                temp[j] = b;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (temp[i] > 53)
        {
            j = i;
            k = i - 1;
            break;
        }
        else if (temp[i] == 53)
        {
            j = i + 1;
            k = i - 1;
            break;
        }
    }
    printf("\nSeek Sequence:\n53 -> ");
    for (i = k; i >= 0; i--)
    {
        headmov += abs(curr - temp[i]);
        curr = temp[i];
        printf("%d -> ", curr);
    }
    if (curr > 0)
    {
        headmov += curr;
        curr = 0;
        printf("%d -> ", curr);
    }
    for (i = j; i < n; i++)
    {
        headmov += abs(curr - temp[i]);
        curr = temp[i];
        printf("%d -> ", curr);
    }
    printf("\nTotal head movements : = %d", headmov);
}
void cscan(int *a, int n)
{

    int temp[n], i, headmov = 0, j, k, curr = 53, b;
    char dir = 'L';
    for (i = 0; i < n; i++)
    {

        temp[i] = *(a + i);
        printf(" %d", temp[i]);
    }
    // Sorting
    for (i = 0; i < n; ++i)
    {

        for (j = i + 1; j < n; ++j)
        {

            if (temp[i] > temp[j])
            {

                b = temp[i];
                temp[i] = temp[j];
                temp[j] = b;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (temp[i] > 53)
        {
            j = i;
            k = i - 1;
            break;
        }
        else if (temp[i] == 53)
        {
            j = i + 1;
            k = i - 1;
            break;
        }
    }
    printf("\nSeek Sequence:\n53 -> ");
    for (i = k; i >= 0; i--)
    {
        headmov += abs(curr - temp[i]);
        curr = temp[i];
        printf("%d -> ", curr);
    }
    if (curr > 0)
    {

        headmov += curr;
        curr = 0;
        printf("%d -> ", curr);
        headmov += 255;
        curr = 255;
        printf("%d -> ", curr);
    }
    for (i = n - 1; i >= j; i--)
    {
        headmov += abs(curr - temp[i]);
        curr = temp[i];
        printf("%d -> ", curr);
    }
    printf("\nTotal head movements :  %d", headmov);
}
void look(int *a, int n)
{
    int temp[n], i, headmov = 0, j, k, curr = 53, b;
    char dir = 'L';
    for (i = 0; i < n; i++)
    {

        temp[i] = *(a + i);
        printf(" %d", temp[i]);
    }
    // Sorting
    for (i = 0; i < n; ++i)
    {

        for (j = i + 1; j < n; ++j)
        {

            if (temp[i] > temp[j])
            {

                b = temp[i];
                temp[i] = temp[j];
                temp[j] = b;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (temp[i] > 53)
        {
            j = i;
            k = i - 1;
            break;
        }
        else if (temp[i] == 53)
        {
            j = i + 1;
            k = i - 1;
            break;
        }
    }
    printf("\nSeek Sequence:\n53 -> ");
    for (i = k; i >= 0; i--)
    {
        headmov += abs(curr - temp[i]);
        curr = temp[i];
        printf("%d -> ", curr);
    }
    for (i = j; i < n; i++)
    {
        headmov += abs(curr - temp[i]);
        curr = temp[i];
        printf("%d -> ", curr);
    }
    printf("\nTotal head movements : = %d", headmov);
}
void clook(int *a, int n)
{
    int temp[n], i, headmov = 0, j, k, curr = 53, b;
    char dir = 'L';
    for (i = 0; i < n; i++)
    {

        temp[i] = *(a + i);
        printf(" %d", temp[i]);
    }
    // Sorting

    for (i = 0; i < n; ++i)
    {

        for (j = i + 1; j < n; ++j)
        {

            if (temp[i] > temp[j])
            {

                b = temp[i];
                temp[i] = temp[j];
                temp[j] = b;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (temp[i] > 53)
        {
            j = i;
            k = i - 1;
            break;
        }
        else if (temp[i] == 53)
        {
            j = i + 1;
            k = i - 1;
            break;
        }
    }
    printf("\nSeek Sequence:\n53 -> ");
    for (i = k; i >= 0; i--)
    {
        headmov += abs(curr - temp[i]);
        curr = temp[i];
        printf("%d -> ", curr);
    }
    headmov += abs(curr - temp[n - 1]);
    curr = temp[n - 1];
    printf("%d -> ", curr);
    for (i = n - 2; i >= j; i--)
    {
        headmov += abs(curr - temp[i]);
        curr = temp[i];
        printf("%d -> ", curr);
    }
    printf("\nTotal head movements : = %d", headmov);
}
int main()
{
     printf("\nBushra Shahzad-21BCS046\n");
    int choice, n;
    int array[1000];
    while (1)
    {
        printf("\n\n0.Input track numbers between 0 to 256!");
        printf("\n1. FCFS");
        printf(" 2. SSTF");
        printf(" 3. SCAN");
        printf(" 4. CSCAN");
        printf(" 5. LOOK");
        printf(" 6. CLOOK");
        printf(" 7. QUIT!\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            printf("Enter no of processes:\n");
            scanf("%d", &n);
            printf("Enter track nos.\n");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &array[i]);
            }
            break;

        case 1:
            fcfs(array, n);
            break;
        case 2:
            sstf(array, n);
            break;

        case 3:
            scan(array, n);
            break;

        case 4:
            cscan(array, n);
            break;

        case 5:
            look(array, n);
            break;

        case 6:
            clook(array, n);
            break;

        case 7:
            exit(0);

        default:
            printf("\nInvalid input!\n");
            break;
        }
    }

    return 0;
}