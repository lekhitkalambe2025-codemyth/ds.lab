#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *head = NULL;

void displayList() {
    Node *ptr = head;

    if (ptr == NULL) {
        printf("List is empty\n");
        return;
    }

    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}


void insertNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node *ptr = head;

        while (ptr->next != NULL) {
            ptr = ptr->next;
        }

        ptr->next = newNode;
        newNode->prev = ptr;
    }

    printf("Inserted successfully\n");
}


void deleteNode(int value) {
    Node *ptr = head;

    if (ptr == NULL) {
        printf("List is empty\n");
        return;
    }

    while (ptr != NULL && ptr->data != value) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Number %d not found\n", value);
        return;
    }


    if (ptr == head) {
        head = ptr->next;
        if (head != NULL) {
            head->prev = NULL;
        }
    } else {
        if (ptr->prev != NULL)
            ptr->prev->next = ptr->next;

        if (ptr->next != NULL)
            ptr->next->prev = ptr->prev;
    }

    free(ptr);

    printf("List after deletion: ");
    displayList();
}


void reverseDLL() {
    Node *current = head;
    Node *temp = NULL;

    if (current == NULL) {
        printf("List is empty\n");
        return;
    }

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL)
        head = temp->prev;

    displayList();
}

void concatenateList() {
    int n, val;
    scanf("%d", &n);

    if (n == 0) {
        printf("Second list is empty\n");
        return;
    }

    Node *secondHead = NULL;
    Node *tail = NULL;

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);

        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = val;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (secondHead == NULL) {
            secondHead = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    if (head == NULL) {
        head = secondHead;
    } else {
        Node *ptr = head;

        while (ptr->next != NULL)
            ptr = ptr->next;

        ptr->next = secondHead;
        secondHead->prev = ptr;
    }

    displayList();
}

int main() {
    int choice, num;

    while (1) {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Reverse\n5.Concatenate\n6.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scanf("%d", &num);
                insertNode(num);
                break;

            case 2:
                scanf("%d", &num);
                deleteNode(num);
                break;

            case 3:
                displayList();
                break;

            case 4:
                reverseDLL();
                break;

            case 5:
                concatenateList();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
