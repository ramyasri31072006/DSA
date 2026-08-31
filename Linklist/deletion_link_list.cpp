#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;
struct node* tail = NULL;

// Function to create a new node
struct node* create_node(int val) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node)); // allocate memory
    new_node->data = val;  // store value
    new_node->next = NULL; // next pointer set to NULL
    return new_node;
}

// Function to insert a value at the end of the list
struct node* insert_val(int val) {
    if (head == NULL) { // If the list is empty
        head = create_node(val);
        tail = head; // tail points to the new node
    } else {
        tail->next = create_node(val); // insert at the end
        tail = tail->next; // update tail to the new node
    }
    return head; // return head to allow for further modifications
}

// Function to delete the first node of the list
struct node* delete_begining(struct node* head) {
    if (head == NULL) {
        printf("The list is already empty.\n");
        return NULL;
    }

    struct node* temp = head;  // Store the current head
    head = head->next;         // Update the head to the next node
    free(temp);                // Free the memory of the removed node
    return head;               // Return the new head
}

// Function to delete the last node of the list
struct node* delete_end(struct node* head) {
    if (head == NULL) {
        printf("The list is already empty.\n");
        return NULL;
    }

    // If there's only one node
    if (head->next == NULL) {
        free(head); // Free the only node
        return NULL; // List becomes empty
    }

    // Traverse the list to find the second-last node
    struct node* temp = head;
    while (temp->next != NULL && temp->next->next != NULL) {
        temp = temp->next;
    }

    // Now temp is the second-last node, remove the last node
    free(temp->next);
    temp->next = NULL; // Set the second-last node's next to NULL
    tail = temp; // Update the tail to the second-last node
    return head;
}

// Function to delete a node from the middle at a specified position
struct node* delete_mid(struct node* head, int pos) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return NULL;
    }

    if (pos < 1) {
        printf("Invalid position.\n");
        return head;
    }

    struct node* temp = head;
    int cnt = 1;

    // Special case for deleting the first node
    if (pos == 1) {
        return delete_begining(head);
    }

    // Traverse to find the node at position (pos - 1)
    while (temp != NULL && cnt < pos - 1) {
        temp = temp->next;
        cnt++;
    }

    // If position is invalid (out of range)
    if (temp == NULL || temp->next == NULL) {
        printf("Position is out of range.\n");
        return head;
    }

    // Delete the node at the specified position
    struct node* del_node = temp->next;
    temp->next = temp->next->next;
    if (temp->next == NULL) { // Update tail if we're deleting the last node
        tail = temp;
    }
    free(del_node); // Free the memory of the deleted node

    return head;
}

// Function to display the linked list
void display(struct node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n); // number of nodes

    // Insert initial values into the linked list
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        head = insert_val(val); // Assign head after each insertion
    }

    // Perform deletion operations
    int pos;
    scanf("%d", &pos);

    // Uncomment one of the delete operations to test
    // head = delete_begining(head); // Delete the first node
    // head = delete_end(head);      // Delete the last node
    head = delete_mid(head, pos); // Delete a node from the middle

    // Display the updated list
    display(head);

    return 0;
}

