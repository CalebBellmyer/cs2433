/*
Name: Caleb Bellmyer
CWID: 11638131
Email-ID: caleb.bellmyer@okstate.edu
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node_struct {
    int element;
    struct Node_struct* nextNode;
} Node;

void Node_Create(Node* thisNode, int elementInit, Node* nextLocation) {
    thisNode->element = elementInit;
    thisNode->nextNode = nextLocation;
}

void printList(Node* head) {
    printf("Linked List: ");
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->element);
        current = current->nextNode;
    }
    printf("NULL\n\n");
}

void insertBeginning(Node** head) {
    int element;
    printf("Enter the element to insert at the beginning: ");
    scanf("%d", &element);

    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->element = element;
    newNode->nextNode = *head;
    *head = newNode; 
   
    printList(*head);
}

void insertEnd(Node** head) {
    int element;
    printf("Enter the element to insert at the end: ");
    scanf("%d", &element);

    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->element = element;
    newNode->nextNode = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->nextNode != NULL) {
            current = current->nextNode;
        }
        current->nextNode = newNode;
    }
    printList(*head);
}

void insertIndex(Node** head) {
    int element;
    int position;
    int count = 1;

    printf("enter the element to insert: ");
    scanf("%d", &element);

    printf("Enter the position to insert at: ");
    scanf("%d", &position);

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->element = element;

    if (position == 1) {
     newNode->nextNode = *head;
    *head = newNode;
    } else {
        Node* current = *head;
        for (int i = 1; current != NULL && i < position - 1; i++) {
            current = current->nextNode;
        }
        if (current == NULL) {
            printf("Position out of bounds!\n");
            free(newNode);
            return;
        }
        newNode->nextNode = current->nextNode;
        current->nextNode = newNode;
    }
    printList(*head);
}

void deleteFirstNode(Node** head) {
    Node* temp = *head;
    *head = (*head)->nextNode;
    free(temp);
    printList(*head);
}

void deleteLastNode(Node** head) {
    if (*head == NULL) {
    printf("The list is empty.\n");
    return;
    }

    if ((*head)->nextNode == NULL) {
        free(*head);
        *head = NULL;
    } else {
        Node* current = *head;
        while (current->nextNode->nextNode != NULL) {
            current = current->nextNode;
        }

        free(current->nextNode);
        current->nextNode = NULL;
    }
    printf("Deleted the last node.\n");
    printList(*head);
}

void deleteIndexNode(Node** head) {
    if (*head == NULL) {
    printf("The list is empty.\n");
    return;
    }

    int position;
    printf("Enter the position of the node to delete: ");
    scanf("%d", &position);

    if (position == 1) {
        deleteFirstNode(head);
        return;
    }
    Node* current = *head;
    for (int i = 1; current != NULL && i < position - 1; i++) {
        current = current->nextNode;
    }
    if (current == NULL || current->nextNode == NULL) {
        printf("Position out of bounds!\n");
        return;
    }
    Node* temp = current->nextNode;
    current->nextNode = temp->nextNode;
    free(temp);
    printList(*head);

}

void init(Node** head) {
    int amount;
    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &amount);

    Node* current = NULL;

    for (int i = 0; i < amount; i++) {
        int element;
        printf("Enter element %d: ", i + 1);
        scanf("%d", &element);

        Node* newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL) {
            printf("Memory allocation failed!\n");
            return;
        }
        Node_Create(newNode, element, NULL);

        if (*head == NULL) {
            *head = newNode;
            current = newNode;
        } else {
            current->nextNode = newNode;
            current = newNode;
        }
    }
    printList(*head);
}

void routing(int choice, Node** head) {
    switch(choice) {
        case 1:
            insertBeginning(head);
            break;
        case 2:
            insertEnd(head);
            break;
        case 3:
            insertIndex(head);
            break;
        case 4:
            deleteFirstNode(head);
            break;
        case 5:
            deleteLastNode(head);
            break;
        case 6:
            deleteIndexNode(head);
            break;
        case 7:
            printf("Exiting the program...\n");
            break;
        default:
            printf("Invalid choice. Please enter a number between 1 and 7.\n");
    }
}

void menu(Node** head) {
    int choice;
    while (1) {
        printf("***************Menu****************\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at a specific position\n");
        printf("4. Delete the first node\n");
        printf("5. Delete the last node\n");
        printf("6. Delete a node at a specific position\n");
        printf("7. Exit\n");
        printf("**************************************\n");
        printf("Enter Your choice: ");
        scanf("%d", &choice);
        if (choice == 7) break;
        routing(choice, head);
    }
}

int main() {
    Node* head = NULL;
    init(&head);
    menu(&head);

    return 0;
}
