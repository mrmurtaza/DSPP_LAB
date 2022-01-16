#include<stdio.h>
#include<stdlib.h>

struct tree{	
	int data;
	struct tree *left;
	struct tree *right;
};

struct Queue{
	int front;
	int rear;
	struct tree *queue[200];	
};


int EnQueue(struct tree *node,struct Queue *Q){

	if(Q->rear==19){
		printf("Queue is full.");
		return 0;
	}
	Q->queue[++Q->rear]=node; //printf("Inserted %d ",node->data);
	return 0;
}

struct tree* DeQueue(struct Queue *Q){
	
	if(Q->front<=Q->rear){
		return Q->queue[Q->front++];	
	}
	printf("Queue is Empty\n");
}

int IsQueueEmpty(struct Queue *Q){

	if(Q->front > Q->rear){ 
		return 1;   
	}
	
	return 0;
}



int insert(struct tree *root, int value){
	
	struct Queue *Q= (struct Queue*)malloc(sizeof(struct Queue));
	Q->front=0;
	Q->rear=-1;
//	Q->queue[Q->rear++]=root;
	struct tree *temp;

	EnQueue(root,Q); // printf("--->%d, %d  ",Q->front,Q->rear);
	while(!IsQueueEmpty(Q)){ 
		
		temp=DeQueue(Q);
		if(temp->left){
			EnQueue(temp->left,Q);
		}
		else if(!temp->left){
			temp->left=malloc(sizeof(struct tree));
			temp->left->left=NULL;
			temp->left->right=NULL;
			temp->left->data=value;    printf(" Inserted %d on the left side\n", temp->left->data);
			break;
		}
		if(temp->right){
			EnQueue(temp->right,Q);
		}
		else if(!temp->right){
			temp->right=malloc(sizeof(struct tree));
			temp->right->left=NULL;
			temp->right->right=NULL;
			temp->right->data=value;  printf(" Inserted %d on the right side\n", temp->right->data);
			break;
		}
		
	}
	return 0;	
}


int printTree(struct tree *root){
	printf("\n");
	struct Queue *Q= (struct Queue*)malloc(sizeof(struct Queue));
	Q->front=0;
	Q->rear=-1;
	struct tree *temp;
	int a=50,x=0;
	int j=0;
	EnQueue(root,Q);
	while(!IsQueueEmpty(Q)){ 
		
		temp=DeQueue(Q);
			for(j=a;j>0;j--){		
				printf(" ");	
			}
			printf("%d",temp->data);
		if(temp->left){
			EnQueue(temp->left,Q);
		}
		if(temp->right){
			EnQueue(temp->right,Q);
		}
		if(x==0||x==2||x==6){
			printf("\n\n\n\n");a=a-a*39/100;	
		}
		x++;			
	}	
}


int InOrderTreePrint(struct tree *root){

	if(root==NULL){
		return 0;
	}
	InOrderTreePrint(root->left);
	printf(" %d ",root->data);
	InOrderTreePrint(root->right);
	return 0;	
}

int PreOrderTreePrint(struct tree *root){

	if(root==NULL){
		return 0;
	}
	printf(" %d ",root->data);
	PreOrderTreePrint(root->left);
	PreOrderTreePrint(root->right);
	return 0;	
}

int PostOrderTreePrint(struct tree *root){

	if(root==NULL){
		return 0;
	}
	PostOrderTreePrint(root->left);
	PostOrderTreePrint(root->right);
	printf(" %d ",root->data);
	return 0;	
}


int height(struct tree *root){
	
	if(!root->left){
		return 0;	
	}
	return height(root->left)+1;		
}



int main(){
	
	struct tree *root=(struct tree*)malloc(sizeof(struct tree));
	root->left=NULL;
	root->right=NULL;
	root->data=1;
	
	insert(root,2);
	insert(root,3);
	insert(root,4);
	insert(root,5);
	insert(root,6);
	insert(root,7);
	insert(root,8);
	
	
	printf("\nHeight of the tree is:- %d\n",height(root));
	
	printf("\nPrinting tree Inorder:-\n");
	InOrderTreePrint(root);
	
	printf("\nPrinting tree Preorder:-\n");
	PreOrderTreePrint(root);
	
	printf("\nPrinting tree Postorder:-\n");
	PostOrderTreePrint(root); 
	
	printTree(root);
	return 0;
}
