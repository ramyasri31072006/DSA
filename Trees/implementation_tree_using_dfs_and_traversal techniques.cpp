#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Binary Tree node
struct node {
    int data;
    struct node* left;
    struct node* right;
};

typedef struct node node;

// Function to create a new node
node* create_node(int val) {
    node* n = (node*)malloc(sizeof(node));
    n->data = val;
    n->right = n->left = NULL;
    return n;
}

// Function for Inorder Traversal (DFS: Left -> Root -> Right)
void inorder(node* root) {
    if (root == NULL) return;
    
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Function for Preorder Traversal (DFS: Root -> Left -> Right)
void preorder(node* root) {
    if (root == NULL) return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Function for Postorder Traversal (DFS: Left -> Right -> Root)
void postorder(node* root) {
    if (root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Function to insert a node into the Binary Tree dynamically
node* insert(node* root, int val) {
    if (root == NULL) 
        return create_node(val);

    // Recursively insert into the left or right subtree
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    return root;
}

// Main function with dynamic user input
int main() {
    node* root = NULL;
    int n, val;

    // Ask user for the number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter node values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);  // Use DFS for inserting values
    }

    // Display tree traversals using DFS
    printf("Inorder Traversal:\n");
    inorder(root);
    printf("\n");

    printf("Preorder Traversal:\n");
    preorder(root);
    printf("\n");

    printf("Postorder Traversal:\n");
    postorder(root);
    printf("\n");

    return 0;
}
