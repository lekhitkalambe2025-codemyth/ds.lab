#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node* NODE;


NODE createNode(int x)
{
    NODE ptr;
    ptr = (NODE) malloc(sizeof(struct node));

    if (ptr == NULL)
        return NULL;

    ptr->data = x;
    ptr->next = NULL;

    return ptr;
}


NODE addNode(NODE head, int x)
{
    NODE nn = createNode(x);
    NODE curr;

    if (head == NULL)
        return nn;

    curr = head;
    while (curr->next)
        curr = curr->next;

    curr->next = nn;
    return head;
}


NODE concatenate(NODE list1, NODE list2)
{
    NODE trav;

    if (list1 == NULL)
        return list2;

    if (list2 == NULL)
        return list1;

    trav = list1;
    while (trav->next)
        trav = trav->next;

    trav->next = list2;
    return list1;
}


void displayList(NODE head)
{
    for (NODE p = head; p != NULL; p = p->next)
        printf("%d --> ", p->data);

    printf("NULL\n");
}
