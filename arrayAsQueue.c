#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value)
{
    if (rear == MAX - 1)
    {
        printf("Queue overflow! Cannot enqueue %d\n", value);
    }
    else
    {
        if (front == -1)
            front = 0;
        queue[++rear] = value;
        printf("%d enqueued to the queue\n", value);
    }
}

int dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue underflow! The queue is empty.\n");
        return -1;
    }
    else
    {
        int dequeuedValue = queue[front];
        front++;
        if (front > rear)
        {
            front = rear = -1;
        }
        return dequeuedValue;
    }
}

void display()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice, value;

    do
    {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            value = dequeue();
            if (value != -1)
            {
                printf("Dequeued value: %d\n", value);
            }
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
