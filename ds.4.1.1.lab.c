#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int value;
    struct Node *next;
} Node;


typedef struct {
    Node *start;
    int count;
} List;


Node* new_node(int val) {
    Node *n = (Node*)malloc(sizeof(Node));
    if (!n) {
        printf("Memory error\n");
        exit(1);
    }
    n->value = val;
    n->next = NULL;
    return n;
}


List* create_list() {
    List *l = (List*)malloc(sizeof(List));
    if (!l) {
        printf("Memory error\n");
        exit(1);
    }
    l->start = NULL;
    l->count = 0;
    return l;
}


void add_at(List *l, int val, int pos) {
    if (pos < 0 || pos > l->count) {
        printf("Invalid position\n");
        return;
    }

    Node *n = new_node(val);

    if (pos == 0) {
        n->next = l->start;
        l->start = n;
    } else {
        Node *temp = l->start;
        for (int i = 0; i < pos - 1; i++)
            temp = temp->next;

        n->next = temp->next;
        temp->next = n;
    }

    l->count++;
    printf("Inserted %d at position %d\n", val, pos);
}


void remove_at(List *l, int pos) {
    if (pos < 0 || pos >= l->count) {
        printf("Invalid position\n");
        return;
    }

    Node *del;

    if (pos == 0) {
        del = l->start;
        l->start = del->next;
    } else {
        Node *temp = l->start;
        for (int i = 0; i < pos - 1; i++)
            temp = temp->next;

        del = temp->next;
        temp->next = del->next;
    }

    free(del);
    l->count--;
    printf("Deleted element at position %d\n", pos);
}


void reverse_list(List *l) {
    Node *prev = NULL, *curr = l->start, *next;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    l->start = prev;
}


void show(List *l) {
    Node *temp = l->start;
    while (temp) {
        printf("%d -> ", temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {
    int n, val, choice, pos;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    List *l = create_list();

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        add_at(l, val, i);
    }

    while (1) {
        printf("\n1.Insert\n2.Delete\n3.Reverse\n4.Display\n5.Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Value: ");
                scanf("%d", &val);
                printf("Position: ");
                scanf("%d", &pos);
                add_at(l, val, pos);
                break;

            case 2:
                printf("Position: ");
                scanf("%d", &pos);
                remove_at(l, pos);
                break;

            case 3:
                reverse_list(l);
                printf("Reversed List: ");
                show(l);
                reverse_list(l);   // restore original
                break;

            case 4:
                printf("List: ");
                show(l);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
