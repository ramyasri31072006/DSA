#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// TreeNode class definition
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Build binary tree from level-order array with -1 as null marker
TreeNode* buildTree(vector<int>& v, int idx, int size) {
    if (idx >= size || v[idx] == -1) return nullptr;

    TreeNode* node = new TreeNode(v[idx]);
    node->left = buildTree(v, 2 * idx + 1, size);
    node->right = buildTree(v, 2 * idx + 2, size);
    return node;
}

// Level-order traversal with level number output
void levelOrder(TreeNode* root) {
    if (root == nullptr) return;

    queue<TreeNode*> q;
    q.push(root);
    int level = 0;

    while (!q.empty()) {
        int size = q.size();
        cout << level++ << " --> ";

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            cout << node->data << " ";

            if (node->left != nullptr) q.push(node->left);
            if (node->right != nullptr) q.push(node->right);
        }

        cout << endl;
    }
}
// vector<vector<int>> levelOrder(Node *root) {
//     // Vector to store the final level order traversal result
//     vector<vector<int>> ans;

//     // If the tree is empty, return the empty result
//     if (root == NULL) return ans;

//     // Queue to help with level-order (BFS) traversal
//     queue<Node*> q;
//     q.push(root); // Start with the root node

//     // Continue while there are nodes to process
//     while (!q.empty()) {
//         int size = q.size(); // Number of nodes at the current level
//         vector<int> level;   // Vector to store the current level's nodes

//         // Process each node at the current level
//         for (int i = 0; i < size; i++) {
//             Node* n = q.front(); // Get the front node
//             q.pop();             // Remove it from the queue

//             // Add the node's left and right children to the queue if they exist
//             if (n->left != NULL) q.push(n->left);
//             if (n->right != NULL) q.push(n->right);

//             // Add the node's data to the current level vector
//             level.push_back(n->data);
//         }

//         // Add the current level's result to the final answer
//         ans.push_back(level);
//     }

//     // Return the complete level order traversal
//     return ans;
// }

int main() {
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i]; // Use -1 for null nodes
    }

    TreeNode* root = buildTree(v, 0, n);
    levelOrder(root);

    return 0;
}
