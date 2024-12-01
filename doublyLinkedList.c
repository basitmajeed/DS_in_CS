#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

void createLinkedList();
void displayList();
void insertEnd(int data);
void insertBegin(int data);
void insertIndex(int data, int position);

int main()
{
    createLinkedList();
    displayList();
    insertBegin(11);
    insertIndex(99, 1);
    insertIndex(71, 2);
    displayList();
    return 0;
}

void createLinkedList()
{
    int n, data;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter data for Node %d: ", i + 1);
        scanf("%d", &data);
        insertEnd(data);
    }
    printf("\nDoubly Linked list created successfully.\n");
}

void displayList()
{
    if (head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    struct node *temp = head;
    printf("\nDoubly Linked List: ");
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insertEnd(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        newNode->prev = NULL;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Inserted %d at the end of the list.\n", data);
}

void insertBegin(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = head;

    if (head != NULL)
    {
        head->prev = newNode;
    }
    newNode->prev = NULL;
    head = newNode;
    printf("Inserted %d at the beginning of the list.\n", data);
}

void insertIndex(int data, int position)
{
    if (position <= 0)
    {
        printf("Invalid position. Position must be greater than 0.\n");
        return;
    }

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;

    if (position == 1)
    {
        insertBegin(data);
        return;
    }

    struct node *temp = head;
    int i;
    for (i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position %d is out of bounds.\n", position);
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }
    temp->next = newNode;

    printf("Inserted %d at position %d of the list.\n", data, position);
}