#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node*pre;
	int data;
	struct node* next;
};
struct node*head=NULL; 
struct node*tail=NULL; 
struct node* create_node(int val){
	struct node*New_node;//create node
	New_node=(struct node*)malloc(sizeof(struct node));//allocate memory
	New_node->data=val;//store value
	New_node->next=NULL;//keep adress as null
	New_node->pre=NULL;
	return New_node; 
}
struct node*insert_val(int val){
	if(head==NULL){//if head was empty 
		head=create_node(val);//stores the created adress of node in head
		tail=head;//to avoid breaking of connetions declare another variable
	}  
	else{//if node was already created
		tail->next=create_node(val);//then store the adress of created node in before node to create connection
		 tail->next->pre=tail;//and update before node adress in newnode prev 
		tail=tail->next;//change tail to point at last node
	}
}
struct node*insert_begining(int iv){
	struct node*bnode;//create node
	bnode=create_node(iv);
	bnode->next=head;//store adress of head in bnode next
	head->pre=bnode;//store adress of bnode in head prev 
	head=bnode;//create connection
	
}
struct node*insert_ending(int iv){
	struct node*enode;//create node
	enode=create_node(iv);
	enode->pre=tail;//store adress of tail in enode prev
tail->next=enode;//create connection
	
}
struct node*insert_middle(int mv,int pos){
	struct node*mnode;//create node
	mnode=create_node(mv);//asign values to node
	struct node* temp=head;//declare pointer to find position to insert
	int cnt=0;
	while(true){//runs to find pos-1 node
		temp=temp->next;
		cnt++;
		if(pos-1==cnt){
			break;
		}
	}
	mnode->next=temp->next;
	temp->next->pre=mnode;//store 'pos' node adress in mnode
	mnode->pre=temp;
	temp->next=mnode;
	//stores 'mnode' adress in pos-1 node
}
void display(struct node*head){
while(head!=NULL){
		printf("%d ",head->data);
		head=head->next; 
 }	
}
int main(){
	int n;
	scanf("%d",&n);//no.of nodes
	for(int i=0;i<n;i++){
		int val;//data that inserted in node.data
		scanf("%d",&val);
		insert_val(val);
	}
    int iv,mv,ev,pos;
	scanf("%d%d%d%d",&iv,&mv,&ev,&pos);
	insert_begining(iv);
	insert_ending(ev); 
	insert_middle(mv,pos);   
	display(head);
	
}
