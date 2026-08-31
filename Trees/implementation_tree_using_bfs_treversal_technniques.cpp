#include <stdlib.h>
#include <stdio.h>

// Structure definition for a Binary Tree node
struct node {
    int data;
    struct node* left;
    struct node* right;
};

typedef struct node node;

// Function to create a new node
node* create_node(int data) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

// Function to insert a value into Binary Tree (Level Order Insertion)
void insert(node** root, int data) {
    node* newnode = create_node(data);
    
    // If the tree is empty, set the new node as root
    if (*root == NULL) {
        *root = newnode;
        return;
    }

    // Using a queue to perform level-order insertion
    node* temp;
    node* queue[100];
    int front = -1, rear = -1;

    queue[++rear] = *root;

    while (front != rear) {
        temp = queue[++front];

        // Insert the node at the first available position (left first)
        if (temp->left == NULL) {
            temp->left = newnode;
            return;
        } else {
            queue[++rear] = temp->left;
        }

        if (temp->right == NULL) {
            temp->right = newnode;
            return;
        } else {
            queue[++rear] = temp->right;
        }
    }
}

// Function for Preorder Traversal (Root -> Left -> Right)
void preorder_traversal(node* root) {
    if (root == NULL) return;

    printf("%d ", root->data);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

// Function for Inorder Traversal (Left -> Root -> Right)
void inorder_traversal(node* root) {
    if (root == NULL) return;

    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
}

// Function for Postorder Traversal (Left -> Right -> Root)
void postorder_traversal(node* root) {
    if (root == NULL) return;

    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%d ", root->data);
}

// Main function with dynamic user input
int main() {
    node* root = NULL;
    int n, val;

    // Ask user for number of nodes
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter node values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insert(&root, val);
    }

    // Print tree traversals
    printf("Preorder Traversal:\n");
    preorder_traversal(root);
    printf("\n");

    printf("Inorder Traversal:\n");
    inorder_traversal(root);
    printf("\n");

    printf("Postorder Traversal:\n");
    postorder_traversal(root);
    printf("\n");

    return 0;
}
