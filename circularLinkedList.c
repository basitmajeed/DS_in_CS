
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode;
    return newNode;
}

void addNode(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

void deleteNode(struct Node **head, int data)
{
    if (*head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    struct Node *temp = *head;
    struct Node *prev = NULL;

    if (temp->data == data)
    {
        if (temp->next == *head)
        {
            free(temp);
            *head = NULL;
            return;
        }
        else
        {
            prev = *head;
            while (prev->next != *head)
            {
                prev = prev->next;
            }
            *head = temp->next;
            prev->next = *head;
            free(temp);
            return;
        }
    }

    while (temp->next != *head && temp->data != data)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp->data == data)
    {
        prev->next = temp->next;
        free(temp);
    }
    else
    {
        printf("Node with data %d not found.\n", data);
    }
}

void displayList(struct Node *head)
{
    if (head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    struct Node *temp = head;
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(head)\n");
}

int main()
{
    struct Node *head = NULL;
    int choice, data;

    do
    {
        printf("\nCircular Linked List Menu:\n");
        printf("1. Add node\n");
        printf("2. Delete node\n");
        printf("3. Display list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to add: ");
            scanf("%d", &data);
            addNode(&head, data);
            break;
        case 2:
            printf("Enter data to delete: ");
            scanf("%d", &data);
            deleteNode(&head, data);
            break;
        case 3:
            displayList(head);
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
