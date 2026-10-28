#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct Node {
    int data;
    struct Node* next;
};

// Function to detect cycle
int detectCycle(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // Moves one step
        fast = fast->next->next;    // Moves two steps

        if (slow == fast) {
            return 1;               // Cycle found
        }
    }

    return 0;                       // No cycle
}

int main() {
    // Creating nodes
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    struct Node* fourth = (struct Node*)malloc(sizeof(struct Node));

    // Assigning data
    head->data = 10;
    second->data = 20;
    third->data = 30;
    fourth->data = 40;

    // Linking nodes
    head->next = second;
    second->next = third;
    third->next = fourth;

    // Creating a cycle:
    fourth->next = second;

    // Checking for cycle
    if (detectCycle(head))
        printf("Cycle detected in the linked list.\n");
    else
        printf("No cycle found in the linked list.\n");

    return 0;
}