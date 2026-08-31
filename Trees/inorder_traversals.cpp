#include <bits/stdc++.h>
using namespace std;
//implementation of binary tree
class TreeNode{
    public:
    int data;
    TreeNode*left;
    TreeNode*right;
    TreeNode(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};

TreeNode* buildTree(vector<int>&v,int idx,int size){
    if(idx>=size)return nullptr;
    TreeNode*node=new TreeNode(v[idx]);//create node
    node->left =buildTree(v,2*idx+1,size);
    node->right = buildTree(v,2*idx+2,size);
    return node;
}
//inorder traversal using dfs
void inorder(TreeNode*root){
    if(root==NULL)return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
//inorder iterative traversal
void inorderI(TreeNode*root){//if you want return vector then change return type to vector<int>
    stack<TreeNode*>st;//create stack
    TreeNode*node=root;//store root
    //vector<int>inorder;
    while(true){
        if(node!=NULL){//if current node not equal to null then push it into stack
            st.push(node);
            node=node->left;//and then move to left
        }
        else{//if we reached to left most node
            if(st.empty())break;//if stack was empty that indicates traversal was done
            node=st.top();//access top
            st.pop();//pop it
            cout<<node->data<<" ";//print data
            //inorder.push_back(node->val);
            node=node->right;//move right
        }
    }
   // return inorder;
}
 //morris traversal-->t-o(n),s-o(1)--->threaded binary tree;
 void inorderm(TreeNode*root){
    //vector<int>inorder;
    TreeNode*cur=root;//intilize cur as root
    while(cur!=NULL){ //while cur not null
        if(cur->left==NULL){//cur left is null 
            //inorder.push_back(cur->data);
            cout<< cur->data<<" ";// print data
            cur=cur->right;// move right
        }
        else{
            TreeNode*prev=cur->left;               //find
            while(prev->right && prev->right!=cur){// right most node of cur left subtree(predecessor)
                prev=prev->right;
            }
            //threading
            if(prev->right==NULL){//make cur as right child of predecessor
                prev->right=cur;
                cur=cur->left;//and move to cur left
            }
            else{
                prev->right=NULL;//remove the thread
                //inorder.push_back(cur->data);
                cout<<cur->data<<" ";//visit cur (print)
                cur=cur->right;//move right
            }

        }
    }
  //return inorder;
 }

int main(){
    //declare size
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    TreeNode*root = buildTree(v,0,n);
    //inorder(root);
    //inorderI(root);
    inorderm(root);
    return 0;
}