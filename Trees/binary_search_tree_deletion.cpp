#include <stdio.h>
#include <stdlib.h>

// Structure for a Binary Search Tree (BST) node
struct bst {
    int data;
    struct bst *left, *right;
};

// Function to create a new node with given value
struct bst* create_node(int val) {
    struct bst *temp = (struct bst*)malloc(sizeof(struct bst));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Function to find the minimum value node in the BST (used for deletion)
struct bst* find_min(struct bst* root) {
    if (root->left == NULL) 
        return root;  // The leftmost node has the minimum value
    else 
        return find_min(root->left);
}

// Function to delete a node with a given value in the BST
struct bst* delete_val(struct bst* root, int val) {
    if (root == NULL) 
        return NULL; // Base case: empty tree or value not found

    // Traverse to the left subtree if the value is smaller
    if (val < root->data) {
        root->left = delete_val(root->left, val);
    }
    // Traverse to the right subtree if the value is greater
    else if (val > root->data) {
        root->right = delete_val(root->right, val);
    }
    // Node to delete found
    else {
        // Case 1: Node has no children (leaf node)
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        // Case 2: Node has one child
        else if (root->left == NULL || root->right == NULL) {
            struct bst* temp;
            if (root->left == NULL) {
                temp = root->right;
            } else {
                temp = root->left;
            }
            free(root);
            return temp; // Replace node with its only child
        }
        // Case 3: Node has two children
        else {
            struct bst* temp = find_min(root->right); // Find minimum in right subtree
            root->data = temp->data; // Copy value to current node
            root->right = delete_val(root->right, temp->data); // Delete the duplicate
        }
    }
    return root; // Return updated tree root
}

// Function to insert a value into BST
struct bst* insert(struct bst* root, int val) {
    if (root == NULL) 
        return create_node(val); // Base case: insert at correct position

    // If value is smaller, insert in left subtree
    if (val < root->data) {
        root->left = insert(root->left, val);
    }
    // If value is larger, insert in right subtree
    else {
        root->right = insert(root->right, val);
    }
    return root;
}

// Inorder Traversal (Left -> Root -> Right), prints sorted values
void inorder(struct bst* root) {
    if (root == NULL) 
        return;
    
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n); // Read number of elements
    struct bst* root = NULL;

    // Insert values into BST
    int val;
    scanf("%d", &val);
    root = insert(root, val);

    for (int i = 1; i < n; i++) {
        int val;
        scanf("%d", &val);
        insert(root, val);
    }

    // Delete a given value
    int value;
    scanf("%d", &value);
    root = delete_val(root, value);

    // Print BST elements in sorted order
    inorder(root);

    return 0;
}
