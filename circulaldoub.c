#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

// Insert at End
void insertEnd(int value) {
    struct node *newnode, *last;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;

    if(head == NULL) {
        head = newnode;
        newnode->next = head;
        newnode->prev = head;
    }
    else {
        last = head->prev;

        newnode->next = head;
        newnode->prev = last;
        last->next = newnode;
        head->prev = newnode;
    }
}

// Insert at Beginning
void insertBegin(int value) {
    struct node *newnode, *last;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;

    if(head == NULL) {
        head = newnode;
        newnode->next = head;
        newnode->prev = head;
    }
    else {
        last = head->prev;

        newnode->next = head;
        newnode->prev = last;
        last->next = newnode;
        head->prev = newnode;
        head = newnode;
    }
}

// Insert at Position
void insertPosition(int value, int pos) {
    struct node *newnode, *temp;
    int i;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;

    temp = head;
    for(i = 1; i < pos-1; i++)
        temp = temp->next;

    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next->prev = newnode;
    temp->next = newnode;
}

// Delete from Beginning
void deleteBegin() {
    struct node *temp, *last;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    if(head->next == head) {
        free(head);
        head = NULL;
    }
    else {
        temp = head;
        last = head->prev;

        head = head->next;
        head->prev = last;
        last->next = head;

        free(temp);
    }
}

// Delete from End
void deleteEnd() {
    struct node *last, *secondlast;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    if(head->next == head) {
        free(head);
        head = NULL;
    }
    else {
        last = head->prev;
        secondlast = last->prev;

        secondlast->next = head;
        head->prev = secondlast;

        free(last);
    }
}

// Delete from Position
void deletePosition(int pos) {
    struct node *temp;
    int i;

    temp = head;
    for(i = 1; i < pos; i++)
        temp = temp->next;

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    if(temp == head)
        head = temp->next;

    free(temp);
}

// Display Forward
void displayForward() {
    struct node *temp;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != head);
}

// Display Backward
void displayBackward() {
    struct node *temp;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head->prev;
    do {
        printf("%d ", temp->data);
        temp = temp->prev;
    } while(temp != head->prev);
}

// Search
void search(int key) {
    struct node *temp = head;
    int found = 0;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    do {
        if(temp->data == key) {
            found = 1;
            break;
        }
        temp = temp->next;
    } while(temp != head);

    if(found)
        printf("Element Found\n");
    else
        printf("Element Not Found\n");
}

int main() {
    int choice, value, pos, key;

    while(1) {
        printf("\n1.Insert End\n2.Insert Beginning\n3.Insert Position\n");
        printf("4.Delete Beginning\n5.Delete End\n6.Delete Position\n");
        printf("7.Display Forward\n8.Display Backward\n9.Search\n0.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertBegin(value);
                break;

            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &pos);
                insertPosition(value, pos);
                break;

            case 4:
                deleteBegin();
                break;

            case 5:
                deleteEnd();
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deletePosition(pos);
                break;

            case 7:
                printf("Forward: ");
                displayForward();
                break;

            case 8:
                printf("Backward: ");
                displayBackward();
                break;

            case 9:
                printf("Enter element to search: ");
                scanf("%d", &key);
                search(key);
                break;

            case 0:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}