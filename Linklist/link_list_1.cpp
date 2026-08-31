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
    struct node* new_node = (struct node*) malloc(sizeof(struct node)); // allocate memory
    new_node->data = val; // store value
    new_node->next = NULL; // next pointer set to NULL
    return new_node;
}

// Function to insert at the end of the list
struct node* insert_val(int val) {
    if (head == NULL) { // If the list is empty
        head = create_node(val);
        tail = head; // tail points to the new node
    } else {
        tail->next = create_node(val); // insert at the end
        tail = tail->next; // update tail to the new node
    }
    return head;
}

// Function to insert at the beginning of the list
struct node* insert_beginning(int iv) {
    struct node* bnode = create_node(iv); // create new node
    bnode->next = head; // link new node to the current head
    head = bnode; // update head to the new node
    return head;
}

// Function to insert at the end of the list
struct node* insert_ending(int iv) {
    struct node* enode = create_node(iv); // create new node
    if (tail != NULL) {
        tail->next = enode; // link new node to the current tail
        tail = enode; // update tail to the new node
    }
    return head;
}

// Function to insert in the middle at a specific position
struct node* insert_middle(int mv, int pos) {
    struct node* mnode = create_node(mv); // create new node
    if (pos == 1) {
        return insert_beginning(mv); // insert at the beginning if position is 1
    }

    struct node* temp = head;
    int cnt = 1;
    while (temp != NULL && cnt < pos - 1) { // traverse to the node before the specified position
        temp = temp->next;
        cnt++;
    }

    if (temp != NULL) { // if valid position found
        mnode->next = temp->next; // link mnode to the next node
        temp->next = mnode; // link previous node to mnode
    }
    return head;
}

// Function to display the linked list
void display(struct node* head) {
    while (head != NULL) {
        printf("%d ", head->data); // print data of the node
        head = head->next; // move to the next node
    }
}

int main() {
    int n;
    scanf("%d", &n); // number of nodes to be created initially

    // Insert initial values into the linked list
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        insert_val(val);
    }

    // Read values for insertions
    int iv, ev, mv, pos;
    scanf("%d %d %d %d", &iv, &ev, &mv, &pos);

    // Insert nodes at different positions
    insert_beginning(iv);
    insert_ending(ev);
    insert_middle(mv, pos);

    // Display the updated list
    display(head);

    return 0;
}

