#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;


/* creating new node */
Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
}

/* printing the linked list */
void print(Node* head)
{
    Node* temp = head;
    printf("List is: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* inserting at beginning */
void insertAtBeginning(Node** head, int data)
{
    Node* newNode = createNode(data);
    if ((*head) == NULL) {
        *head = newNode;
    }
    else {
        newNode->next = *head;
        *head = newNode;
    }
}

/* inserting at end */
void insertAtEnd(Node** head, int data)
{
    Node* newNode = createNode(data);
    if ((*head) == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}

/* inserting after a specified index (0-indexed) */
void insertAtIndex(Node** head, int data, int index)
{
    Node* newNode = createNode(data);
    if (index == 0 || (*head) == NULL) {
        insertAtBeginning(head, data);
        return;
    }
    int counter = 0;
    Node* temp = *head;
    while (temp->next != NULL && counter < index - 1) {
        temp = temp->next;
        counter++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

/* delete from beginning */
void deleteFromBeginning(Node** head)
{
    if ((*head) == NULL) return;
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

/* delete from end */
void deleteFromEnd(Node** head)
{
    if ((*head) == NULL) return;
    Node* temp = *head;
    if ((*head)->next == NULL) {
        free(*head);
        head = NULL;
        return;
    }
    while (temp->next->next != NULL) temp = temp->next;
    Node* lastNode = temp->next;
    temp->next = NULL;
    free(lastNode);
}

/* delete from any index */
void deleteFromIndex(Node** head, int index)
{
    if (index == 0 || (*head) == NULL) {
        deleteFromBeginning(head);
        return;
    }
    int counter = 0;
    Node* temp = *head;
    while (temp->next->next != NULL && counter < index - 1) {
        temp = temp->next;
        counter++;
    }
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
}

int main()
{
    Node* head = NULL;
    while (1) {
        printf("Press 1 to add a node, and 2 to delete a node, and 3 to exit.\n");
        printf("Enter your choice: \n");
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Press 1 to add node at beginning, 2 to add node at end, and 3 to add node after a certain index.\n");
            printf("Enter your choice: \n");
            scanf("%d", &choice);
            int value;
            printf("Enter the value to be added to the list:\n");
            scanf("%d", &value);
            if (choice == 1) {
                insertAtBeginning(&head, value);
            }
            else if (choice == 2) {
                insertAtEnd(&head, value);
            }
            else if (choice == 3) {
                printf("Enter the index at which you want to enter the value:\n");
                int index;
                scanf("%d", &index);
                insertAtIndex(&head, value, index);
            }
            else {
                printf("Wrong choice entered!\n");
            }
        }
        else if (choice == 2) {
            printf("Press 1 to delete node from beginning, 2 to delete node from end, and 3 to delete node from any index.\n");
            printf("Enter your choice: \n");
            scanf("%d", &choice);
            if (choice == 1) {
                deleteFromBeginning(&head);
            }
            else if (choice == 2) {
                deleteFromEnd(&head);
            }
            else if (choice == 3) {
                printf("Enter the index that you want to delete from:\n");
                int index;
                scanf("%d", &index);
                deleteFromIndex(&head, index);
            }
            else {
                printf("Wrong choice entered.\n");
            }
        }
        else if (choice == 3) {
            return 0;
        }
        else {
            printf("Wrong choice entered!");
        }
        print(head);
    }
    return 0;
}
