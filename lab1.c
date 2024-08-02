#include <stdio.h>
#include <stdlib.h>
struct node
{
    char process_name[4];
    int process_priority;
    int process_burst_time;
    struct node *next;
};
struct node *head = NULL;
void insert_process()
{
    struct node *temp, *ptr;
    int time_cal = 0;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the process name:");
    getchar();
    gets(temp->process_name);
    printf("Enter process priority : ");
    scanf("%d", &temp->process_priority);
    printf("Enter process burst time : ");
    scanf("%d", &temp->process_burst_time);
    time_cal = temp->process_burst_time;
    if (head == NULL || temp->process_priority < head->process_priority)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL && temp->process_priority > ptr->process_priority)
        {
            ptr = ptr->next;
        }
        temp->next = ptr->next;
        ptr->next = temp;
    }
}
void execute_process()
{
    struct node *temp;
    temp = head;
    int time_total = 0;
    printf("Process Name\tPriority\tBT\tStart Time\tEnd Time\n");
    while (temp != NULL)
    {
        printf("%s\t\t", temp->process_name);
        printf("%d\t\t", temp->process_priority);
        printf("%d\t", temp->process_burst_time);
        printf("%d\t\t", time_total);
        time_total += temp->process_burst_time;
        printf("%d\n", time_total);
        temp = temp->next;
    }
}
int main()
{
    int choice;
    printf("Bushra Shahzad-21BCS046");
    while (1)
    {
        printf("\nEnter\n1. Insert a process.\n2. Execute all processes.\n3. Exit!\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert_process();
            execute_process();
            break;
        case 2:
            execute_process();
            head = NULL;
            printf("\nProcesses Executed!\n");
            break;
        case 3:
            exit(0);
            break;

        default:
            break;
        }
    }
    return 0;
}