#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};
struct node* createnode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
void addnode(struct node** head, int data) {
    struct node* newnode = createnode(data);

    if (*head == NULL) {
        *head = newnode;
    } else {
        struct node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void deletenodeByLocation(struct node** head, int location) {
    if (*head == NULL) {
        printf("List is empty. Unable to delete.\n");
        return;
    }

    struct node* temp = *head;

    if (location == 1) {
        *head = temp->next;
        free(temp);
        return;
    }

    int i;
    for (i = 1; i < location - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid location. Unable to delete.\n");
        return;
    }

    struct node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
}
void deletenodesByData(struct node** head, int data) {
    struct node* current = *head;
    struct node* previous = NULL;

    while (current != NULL) {
        if (current->data == data) {
            if (previous == NULL) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            struct node* nodeToDelete = current;
            current = current->next;
            free(nodeToDelete);
        } else {
            previous = current;
            current = current->next;
        }
    }
}

void deleteLinkedList(struct node** head) {
    struct node* current = *head;
    struct node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}

void displayLinkedList(struct node* head) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node* head = NULL;

    // Adding nodes to the linked list
    addnode(&head, 1);
    addnode(&head, 2);
    addnode(&head, 3);
    addnode(&head, 4);
    addnode(&head, 5);
    addnode(&head, 5);
    addnode(&head, 6);

    printf("Initial linked list: ");
    displayLinkedList(head);

    // Deleting all nodes with data value 5
    int dataToDelete = 5;
    deletenodesByData(&head, dataToDelete);
    printf("After deleting nodes with data %d: ", dataToDelete);
    displayLinkedList(head);

    // Deleting the complete linked list
    deleteLinkedList(&head);
    printf("After deleting the complete linked list: ");
    displayLinkedList(head);
    // Deleting a node by location
    int locationToDelete = 3;
    deletenodeByLocation(&head, locationToDelete);
    printf("After deleting node at location %d: ", locationToDelete);
    displayLinkedList(head);


    return 0;
}

