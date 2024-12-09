#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

void createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    if (root == NULL)
    {
        root = newNode;
    }
    else
    {
        struct node *temp = root;
        while (temp != NULL)
        {
            if (temp->left == NULL)
            {
                temp->left = newNode;
                return;
            }
            else if (temp->right == NULL)
            {
                temp->right = newNode;
                return;
            }
            temp = temp->right;
        }
    }
}

void preOrderTraversal(struct node *node)
{
    if (node != NULL)
    {
        printf("%d ", node->data);
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }
}

void inOrderTraversal(struct node *node)
{
    if (node != NULL)
    {
        inOrderTraversal(node->left);
        printf("%d ", node->data);
        inOrderTraversal(node->right);
    }
}

void postOrderTraversal(struct node *node)
{
    if (node != NULL)
    {
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        printf("%d ", node->data);
    }
}

int main()
{
    createNode(10);
    createNode(20);
    createNode(30);
    createNode(40);
    createNode(50);
    createNode(60);
    createNode(70);
    createNode(80);

    printf("Tree contents (pre-order): ");
    preOrderTraversal(root);
    printf("\n");
    printf("Tree contents (in-order): ");
    inOrderTraversal(root);
    printf("\n");
    printf("Tree contents (post-order): ");
    postOrderTraversal(root);
    printf("\n");
    printTree(root);

    return 0;
}
