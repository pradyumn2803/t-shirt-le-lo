#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->left = NULL;
    n->right = NULL;
    n->data = data;
    return n;
}

//Recursive Search
struct node *search(struct node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        return root;
    }
    else if (root->data > key)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}

//Iterative Search
struct node *searchIter(struct node *root, int key)
{
    while (root != NULL)
    {
        if (root->data == key)
        {
            return root;
        }
        else if (root->data > key)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
}

int main()
{
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);


    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;


    struct node *n = searchIter(p, 5);
    if (n != NULL)
    {
        printf("Found : %d", n->data);
    }
    else
    {
        printf("Element not found");
    }

    return 0;
}
