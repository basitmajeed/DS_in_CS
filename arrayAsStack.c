#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];
int front = -1, rear = -1;

void push(int value)
{
    if (rear == MAX - 1)
    {
        printf("Stack overflow! Cannot push %d\n", value);
    }
    else
    {
        if (front == -1)
            front = 0;
        stack[++rear] = value;
        printf("%d pushed onto stack\n", value);
    }
}

int pop()
{
    if (rear == -1)
    {
        printf("Stack underflow! The stack is empty.\n");
        return -1;
    }
    else
    {
        int poppedValue = stack[rear];
        rear--;
        if (rear == -1)
            front = -1;
        return poppedValue;
    }
}

int main()
{
    int choice, value;

    do
    {
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            value = pop();
            if (value != -1)
            {
                printf("Popped value: %d\n", value);
            }
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice, please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
