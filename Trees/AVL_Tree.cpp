/*
========================================================
AVL TREE IMPLEMENTATION (WITH INTUITION)
========================================================

🧠 INTUITION:

A normal Binary Search Tree (BST) can become skewed 
(like a linked list) when elements are inserted in 
sorted order. This makes operations slow (O(n)).

To solve this, AVL Tree maintains balance automatically.

👉 Key Idea:
After every insertion or deletion, we check whether 
the tree is balanced or not.

Balance Factor = Height(left subtree) - Height(right subtree)

Allowed values:
    -1 → Balanced
     0 → Balanced
    +1 → Balanced

If balance factor goes beyond this range → Tree becomes unbalanced

--------------------------------------------------------
🔄 HOW DO WE FIX IMBALANCE?

We use rotations:

1. LL Case → Right Rotation
2. RR Case → Left Rotation
3. LR Case → Left Rotation + Right Rotation
4. RL Case → Right Rotation + Left Rotation

These rotations restructure the tree while maintaining
BST properties.

--------------------------------------------------------
⚙️ OPERATIONS OVERVIEW

✔ INSERT:
- Insert like BST
- Update height
- Check balance
- Apply rotation if needed

✔ DELETE:
- Delete like BST
- Update height
- Rebalance using rotations

✔ SEARCH:
- Same as BST (O(log n))

✔ TRAVERSAL:
- Inorder gives sorted output

--------------------------------------------------------
⏱ TIME COMPLEXITY

Insertion  : O(log n)
Deletion   : O(log n)
Search     : O(log n)

--------------------------------------------------------
🎯 SUMMARY

AVL Tree ensures:
✔ Fast operations (logarithmic time)
✔ Always balanced tree
✔ Efficient searching and updates

========================================================
*/
#include <bits/stdc++.h>
using namespace std;

// Node structure for AVL Tree
class TreeNode{
public:
    int data;       // value of node
    int height;     // height of node
    TreeNode* left; 
    TreeNode* right;

    // Constructor
    TreeNode(int val){
        data = val;
        left = NULL;
        right = NULL;
        height = 1; // new node has height 1
    }
};

// Function to get height of node
int Height(TreeNode* node){
    if(node == NULL) return 0;
    return node->height;
}

// Right Rotation (LL Case)
TreeNode* rightrotation(TreeNode* p){
    TreeNode *c = p->left;   // child
    TreeNode *gc = c->right; // grandchild

    // Perform rotation
    c->right = p;
    p->left = gc;

    // Update heights
    p->height = 1 + max(Height(p->left), Height(p->right));
    c->height = 1 + max(Height(c->left), Height(c->right));

    return c; // new root after rotation
}

// Left Rotation (RR Case)
TreeNode* leftrotation(TreeNode* p){
    TreeNode* c = p->right;  // child
    TreeNode* gc = c->left;  // grandchild

    // Perform rotation
    c->left = p;
    p->right = gc;

    // Update heights
    p->height = 1 + max(Height(p->left), Height(p->right));
    c->height = 1 + max(Height(c->left), Height(c->right));
    
    return c; // new root
}

// Insert into AVL Tree
TreeNode* Insert(TreeNode* root, int val){
    // Base case: insert node
    if(root == NULL) return new TreeNode(val);

    // Normal BST insertion
    if(val < root->data){
        root->left = Insert(root->left, val);
    }
    else if(val > root->data){
        root->right = Insert(root->right, val);
    }
    else {
        return root; // duplicates not allowed
    }

    // Update height
    root->height = 1 + max(Height(root->left), Height(root->right));

    // Get balance factor
    int balancefactor = Height(root->left) - Height(root->right);

    // LL Case
    if(balancefactor > 1 && val < root->left->data){
        return rightrotation(root);
    }

    // RR Case
    if(balancefactor < -1 && val > root->right->data){
        return leftrotation(root);
    }

    // LR Case
    if(balancefactor > 1 && val > root->left->data){
        root->left = leftrotation(root->left);
        return rightrotation(root);
    }

    // RL Case
    if(balancefactor < -1 && val < root->right->data){
        root->right = rightrotation(root->right);
        return leftrotation(root);
    }

    return root;
}

// Insert multiple elements into AVL Tree
TreeNode* BSTInsertion(vector<int>& arr){
    int len = arr.size();
    if(len == 0) return NULL;

    TreeNode* root = NULL;

    for(int i = 0; i < len; i++){
        root = Insert(root, arr[i]);
    }

    return root;
}

// Search in AVL Tree
bool Search(TreeNode* root, int key){
    if(root == NULL) return false;

    if(root->data == key) return true;

    if(key < root->data){
        return Search(root->left, key);
    }
    else{
        return Search(root->right, key);
    }
}

// Find minimum node (used in deletion)
TreeNode* Findmin(TreeNode* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

// Delete node from AVL Tree
TreeNode* Delete(TreeNode* root, int key){
    if(root == NULL) return NULL;

    // Perform BST deletion
    if(key < root->data){
        root->left = Delete(root->left, key);
    }
    else if(key > root->data){
        root->right = Delete(root->right, key);
    }
    else{
        // Case 1: No child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        // Case 2: One child
        else if(root->left == NULL || root->right == NULL){
            TreeNode* temp = root->left ? root->left : root->right;
            delete root;
            return temp;
        }
        // Case 3: Two children
        else{
            TreeNode* temp = Findmin(root->right); // inorder successor
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }

    if(root == NULL) return root;

    // Update height
    root->height = 1 + max(Height(root->left), Height(root->right));

    // Get balance factor
    int balance = Height(root->left) - Height(root->right);

    // LL Case
    if(balance > 1 && Height(root->left->left) >= Height(root->left->right))
        return rightrotation(root);

    // LR Case
    if(balance > 1 && Height(root->left->left) < Height(root->left->right)){
        root->left = leftrotation(root->left);
        return rightrotation(root);
    }

    // RR Case
    if(balance < -1 && Height(root->right->right) >= Height(root->right->left))
        return leftrotation(root);

    // RL Case
    if(balance < -1 && Height(root->right->right) < Height(root->right->left)){
        root->right = rightrotation(root->right);
        return leftrotation(root);
    }

    return root;
}

// Inorder Traversal (prints sorted order)
void Inorder(TreeNode* root){
    if(root == NULL) return;

    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

// Driver code
int main(){

    vector<int> arr = {3,2,1,6,5,4};

    // Build AVL Tree
    TreeNode* root = BSTInsertion(arr);

    // Print inorder traversal
    cout << "Inorder Traversal: ";
    Inorder(root);
    cout << "\n";

    // Search key
    int key = 5;
    bool find = Search(root, key);

    if(find) cout << "Key Found\n";
    else cout << "Key Not Found\n";

    // Delete key
    root = Delete(root, key);

    cout << "After Deletion: ";
    Inorder(root);
}