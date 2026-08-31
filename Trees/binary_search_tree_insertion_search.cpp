#include<stdio.h>
#include<stdlib.h>
struct bst{
	int data;
	struct bst*left,*right;
};
typedef struct bst bst;
 bst* create_node(int val){
 	bst*newnode=(bst*)malloc(sizeof(bst));
 	newnode->data=val;
 	newnode->left=NULL;
 	newnode->right=NULL;
 	return newnode;
 }
bst*insert(int val,bst*root){
	if(root==NULL)return create_node(val);
	else if (val<root->data){
		root->left=insert(val,root->left);
	}
	else if(val>root->data){
		root->right=insert(val,root->right);
	}
	return root;
}
void inorder(bst*root){
	if(root==NULL)return;
inorder(root->left);
printf("%d ",root->data);
inorder(root->right);
}
int search(int target,bst*root){
	if(root==NULL)return 0;
	if(root->data==target){
		return 1;
	}
	if(target<root->data){
		return search(target,root->left);
	}
	else{
		return search(target,root->right);
	}
	return 0;
}
int main(){
	int n;
	scanf("%d",&n);
	bst*root=NULL;
	for(int i=0;i<n;i++){
		int val;
		scanf("%d",&val);
		root=insert(val,root);	
	}
	inorder(root);
	printf("\n");
	int target;
	scanf("%d",&target);
   if(search(target,root)){
   	printf("found\n");
   	
   }
   else{
   	printf("not found\n");
   }
}
