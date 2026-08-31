<!-- Intuition Behind the Code

This code reconstructs a binary tree from its inorder and preorder traversals.

   * Preorder traversal visits nodes in the order: root -> left subtree -> right subtree.

   * Inorder traversal visits nodes in the order: left subtree -> root -> right subtree.

Using this information:

 1. first element in the preorder array is always the root of the tree (or subtree).

 2. Using the root value, we find its index in the inorder array. This splits the inorder array into:

  * Left subtree elements (all elements to the left of the root index)

  * Right subtree elements (all elements to the right of the root index)

 3. Recursively, the same process is applied to build the left and right subtrees using slices of the inorder array and advancing through the preorder array.

 4. The recursion stops when there are no elements left in the current inorder range (left > right).

This approach efficiently rebuilds the original tree --> 

class Solution {
private:
  // Recursive helper function to construct the tree
  // m: hashmap to quickly find index of root in inorder array
  // preorder: preorder traversal array
  // preIdx: current index in preorder traversal (passed by reference)
  // left, right: current bounds for inorder array segment
  Node* construct(unordered_map<int,int>& m, vector<int>& preorder,
                  int& preIdx, int left, int right) {
      
      // Base case: if left > right, no elements to form a subtree
      if (left > right) {
          return NULL;
      }
      
      // The current root value is the current element in preorder
      int root_val = preorder[preIdx];
      preIdx++; // move to next root in preorder traversal
      
      // Create new node for the root
      Node* root = new Node(root_val);
      
      // Find index of root in inorder traversal to split left/right subtrees
      int idx = m[root_val];
      
      // Recursively construct left subtree from inorder[left..idx-1]
      root->left = construct(m, preorder, preIdx, left, idx - 1);
      
      // Recursively construct right subtree from inorder[idx+1..right]
      root->right = construct(m, preorder, preIdx, idx + 1, right);
      
      return root; // return constructed subtree root
  }
  
public:
  Node* buildTree(vector<int>& inorder, vector<int>& preorder) {
      // Map to store element -> index mappings for inorder traversal
      unordered_map<int,int> m;
      for (int i = 0; i < inorder.size(); i++) {
          m[inorder[i]] = i;
      }
      
      int l = 0;               // left bound for inorder traversal
      int r = inorder.size() - 1; // right bound for inorder traversal
      int preIdx = 0;          // current index in preorder traversal
      
      // Build tree using helper function and return root
      Node* root = construct(m, preorder, preIdx, l, r);
      return root;
  }
};
