#include <stdio.h>
#include <stdlib.h>
struct mem
{
    int size;
    int proc;
    int procSize;
} a[50];
struct node
{
    int pro;
    int size;
    struct node *next;
} *head = NULL, *tail = NULL;

void display(int intFrag, int k)
{
    int extFrag = 0;
    printf("\nP-id\tPro-Size\tLeft-Memory\n");
    for (int i = 0; i < k; i++)
    {
        if (a[i].proc == 0)
        {
            extFrag += a[i].size;
            printf("%d\t 0\t\t%d", a[i].proc, a[i].size);
        }
        else
        {
            printf("%d\t%d\t\t%d", a[i].proc, a[i].procSize, a[i].size);
        }
        printf("\n");
    }
    printf("\nInternal fragmentation : %d", intFrag);
    printf("\nExternal fragmentation : %d", extFrag);
}

void main()
{
     printf("\nBushra Shahzad-21BCS046\n");
    int c = 0, ch, p = 0;
    int intFrag = 0;
    struct node *temp;
    printf("\nEnter the number of memory blocks : \n");
    int k;
    scanf("%d", &k);
    printf("\nEnter the size of each memory block : \n");
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &a[i].size);
        a[i].proc = 0;
    }
    while (1)
    {
        printf("\n1. Enter process.\n2. Best fit.\n3. Worst fit.\n4. First fit.\n5. Change memory blocks. \n6. Quit!\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            struct node *newNode = (struct node *)malloc(sizeof(struct node));
            printf("\nEnter the size of the process : \n");
            scanf("%d", &newNode->size);
            p++;
            newNode->pro = p;
            newNode->next = NULL;
            if (head == NULL)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
            break;
        }
        case 2:
        {
            // best fit

            temp = head;
            int diff;
            int p;
            printf("\nBest Fit : \n");
            while (temp != NULL)
            {
                p = -1;
                diff = -1;
                for (int i = 0; i < k; i++)
                {
                    if (a[i].proc == 0)
                    {
                        if (temp->size <= a[i].size)
                        {
                            if (a[i].size - temp->size <= diff || diff == -1)
                            {
                                diff = a[i].size - temp->size;
                                p = i;
                            }
                        }
                    }
                }

                if (p == -1)
                {
                    printf("Process id %d of size %d could not be allocated!", temp->pro, temp->size);
                    temp = temp->next;
                }
                else
                {
                    a[p].proc = temp->pro;
                    a[p].procSize = temp->size;

                    intFrag += a[p].size - a[p].procSize;
                    a[p].size = a[p].size - a[p].procSize;

                    temp = temp->next;
                }
            }
            head = NULL;
            tail = NULL;
            display(intFrag, k);
            break;
        }
        case 3:
        {
            // worst fit
            temp = head;
            int diff;
            int p;
            int i;
            printf("\nWorst Fit : \n");
            while (temp != NULL)
            {
                p = -1;
                diff = -1;
                for (i = 0; i < k; i++)
                {
                    if (a[i].proc == 0)
                    {
                        if (temp->size <= a[i].size)
                        {
                            if (a[i].size - temp->size >= diff)
                            {
                                diff = a[i].size - temp->size;
                                p = i;
                            }
                        }
                    }
                }

                if (p == -1)
                {
                    printf("Process id %d of size %d could not be allocated!", temp->pro, temp->size);
                    temp = temp->next;
                }
                else
                {
                    a[p].proc = temp->pro;
                    a[p].procSize = temp->size;

                    intFrag += a[p].size - a[p].procSize;
                    a[p].size = a[p].size - a[p].procSize;

                    temp = temp->next;
                }
            }
            head = NULL;
            tail = NULL;
            display(intFrag, k);
            break;
        }
        case 4:
        {
            // first fit
            int p;
            temp = head;
            printf("\nFirst Fit : \n");
            while (temp != NULL)
            {
                p = -1;
                for (int i = 0; i < k; i++)
                {
                    if (a[i].proc == 0)
                    {
                        if (temp->size <= a[i].size)
                        {
                            a[i].proc = temp->pro;
                            a[i].procSize = temp->size;
                            p = 1;
                            intFrag += a[i].size - a[i].procSize;
                            a[i].size = a[i].size - a[i].procSize;
                            break;
                        }
                    }
                }

                if (p == -1)
                {
                    printf("Process id %d of size %d could not be allocated!", temp->pro, temp->size);
                    temp = temp->next;
                }
                else
                {
                    temp = temp->next;
                }
            }
            head = NULL;
            tail = NULL;
            display(intFrag, k);
            break;
        }
        case 5:
        {
            printf("\nEnter the number of memory blocks : \n");
            scanf("%d", &k);
            printf("\nEnter the size of each memory block : \n");
            for (int i = 0; i < k; i++)
            {
                scanf("%d", &a[i].size);
                a[i].proc = 0;
            }
        }
        case 6:
        {
            exit(0);
        }
        default:
        {
            printf("Invalid Input");
        }
        }
    }
}
