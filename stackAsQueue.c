#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int stack1[MAX], stack2[MAX];

int top1 = -1, top2 = -1;

void push(int stack[], int *top, int value)
{
    if (*top < MAX - 1)
    {
        stack[++(*top)] = value;
    }
    else
    {
        printf("Stack Overflow\n");
    }
}

int pop(int stack[], int *top)
{
    if (*top >= 0)
    {
        return stack[(*top)--];
    }
    else
    {
        printf("Stack Underflow\n");
        return -1;
    }
}

void enqueue(int value)
{
    push(stack1, &top1, value);
}

int dequeue()
{
    if (top1 == -1 && top2 == -1)
    {
        printf("Queue is empty\n");
        return -1;
    }

    if (top2 == -1)
    {
        while (top1 >= 0)
        {
            push(stack2, &top2, pop(stack1, &top1));
        }
    }

    return pop(stack2, &top2);
}

void displayQueue()
{
    if (top2 >= 0)
    {
        printf("Queue: ");
        for (int i = top2; i >= 0; i--)
        {
            printf("%d ", stack2[i]);
        }
    }

    if (top1 >= 0)
    {
        if (top2 >= 0)
            printf(" ");
        for (int i = 0; i <= top1; i++)
        {
            printf("%d ", stack1[i]);
        }
    }

    if (top1 == -1 && top2 == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("\n");
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    displayQueue();
    dequeue();
    displayQueue();
    dequeue();
    dequeue();
    displayQueue();

    return 0;
}
