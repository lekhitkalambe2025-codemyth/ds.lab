#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node* NODE;


NODE createNodeInCLL(int value)
{
    NODE newnode = (NODE)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}


NODE createCLL(int n)
{
    NODE first = NULL, last = NULL, temp;
    int val,i;

    for(i=1;i<=n;i++)
    {
        scanf("%d",&val);
        temp = createNodeInCLL(val);

        if(first==NULL)
        {
            first = temp;
            last = temp;
            last->next = first;
        }
        else
        {
            last->next = temp;
            last = temp;
            last->next = first;
        }
    }
    return first;
}


void traverseListInCLL(NODE first)
{
    NODE ptr = first;

    do{
        printf("%d -> ",ptr->data);
        ptr = ptr->next;
    }while(ptr!=first);

    printf("\n");
}


NODE insertAtPositionInCLL(NODE first,int pos,int x)
{
    NODE newnode = createNodeInCLL(x);

    if(pos==1)
    {
        if(first==NULL)
        {
            newnode->next = newnode;
            return newnode;
        }

        NODE last = first;
        while(last->next!=first)
            last = last->next;

        newnode->next = first;
        last->next = newnode;
        first = newnode;

        return first;
    }

    NODE cur = first;
    int i;

    for(i=1;i<pos-1;i++)
    {
        cur = cur->next;

        if(cur==first)
        {
            printf("Position not found\n");
            return first;
        }
    }

    newnode->next = cur->next;
    cur->next = newnode;

    return first;
}


NODE deleteAtPositionInCLL(NODE first,int pos)
{
    NODE temp = first, prev = NULL;
    int i;

    if(pos==1)
    {
        NODE last = first;

        while(last->next!=first)
            last = last->next;

        printf("Deleted element: %d\n",first->data);

        if(first->next==first)
        {
            free(first);
            return NULL;
        }

        first = first->next;
        last->next = first;
        free(temp);

        return first;
    }

    for(i=1;i<pos;i++)
    {
        prev = temp;
        temp = temp->next;

        if(temp==first)
        {
            printf("Position not found\n");
            return first;
        }
    }

    prev->next = temp->next;
    printf("Deleted element: %d\n",temp->data);
    free(temp);

    return first;
}


NODE reverseCLL(NODE first)
{
    NODE prev = NULL,current = first,next = NULL;
    NODE last = first;

    while(last->next!=first)
        last = last->next;

    do{
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }while(current!=first);

    first->next = prev;
    first = prev;

    return first;
}


NODE concatCLL(NODE first,NODE second)
{
    if(first==NULL)
        return second;

    if(second==NULL)
        return first;

    NODE temp1 = first;
    NODE temp2 = second;

    while(temp1->next!=first)
        temp1 = temp1->next;

    while(temp2->next!=second)
        temp2 = temp2->next;

    temp1->next = second;
    temp2->next = first;

    return first;
}

int main()
{
    NODE first = NULL, second = NULL;
    int choice,n,pos,x;

    while(1)
    {
        printf("1.Create 2.Insert 3.Delete 4.Display 5.Reverse 6.Concat 7.Exit\n");
        printf("choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("How many nodes? ");
                scanf("%d",&n);
                first = createCLL(n);
                break;

            case 2:
                printf("Position: ");
                scanf("%d",&pos);

                if(pos<=0)
                {
                    printf("Position not found\n");
                }
                else
                {
                    printf("Element: ");
                    scanf("%d",&x);
                    first = insertAtPositionInCLL(first,pos,x);
                }
                break;

            case 3:
                if(first==NULL)
                {
                    printf("CLL is empty\n");
                }
                else
                {
                    printf("Position: ");
                    scanf("%d",&pos);
                    first = deleteAtPositionInCLL(first,pos);
                }
                break;

            case 4:
                if(first==NULL)
                {
                    printf("CLL is empty\n");
                }
                else
                {
                    printf("Elements in CLL are: ");
                    traverseListInCLL(first);
                }
                break;

            case 5:
                if(first==NULL)
                {
                    printf("CLL is empty\n");
                }
                else
                {
                    first = reverseCLL(first);
                    printf("CLL reversed\n");
                    traverseListInCLL(first);
                }
                break;

            case 6:
                printf("Creating second CLL to concatenate...\n");
                printf("How many nodes in second CLL? ");
                scanf("%d",&n);

                second = createCLL(n);
                first = concatCLL(first,second);

                printf("Concatenated CLL:\n");
                traverseListInCLL(first);
                break;

            case 7:
                exit(0);
        }
    }
}
