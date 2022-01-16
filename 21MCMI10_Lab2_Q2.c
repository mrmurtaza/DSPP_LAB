#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node{
	int binary;
	struct node* next;
};


int insert(struct node *root,int x){
	
	struct node *newNode=(struct node*)malloc(sizeof(struct node));
	struct node *temp=root;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	
	temp->next =newNode;
	newNode->next=NULL;
	newNode->binary=x;
	return 0;
}

int BinaryToDecimal(struct node *root){
	
	struct node *temp=root;
	int a[20],i=0;
	a[0]=temp->binary;
	while(temp->next!=NULL){
		i++;
		a[i]=temp->binary; //printf("%d ",a[i]);
		temp=temp->next;
	}	
	
	int sum=0,j=0;
	while(i!=-1){
		int ex=pow(2,i);
		sum=sum+a[i]*ex;	//printf("Pow(%d) is %d ,",i,ex);
		i--;
	}
	printf("\nDecimal is %d \n",sum);
	return;
}

int printList(struct node *root){
		
	struct node *temp=root;
	printf("List of nodes: %d ",temp->binary);
	while(temp->next!=NULL){
		printf("%d ",temp->binary);
		temp=temp->next;
	}
	return 0;
}


int main(){
	
	struct node *root=(struct node*)malloc(sizeof(struct node));
	printf("Enter binary no. for root element\n");
	int a;
	scanf("%d",&a);
	root->binary=a;
	root->next=NULL;
	while(1){
		
		printf("\nEnter option:\n");
		printf("1) Insert new node\n");
		printf("2) Calculate decimal\n");
		printf("3) Exit\n");

		scanf("%d",&a);
		
		if(a==1){
			printf("Enter binary no.\n");
			int b;
			scanf("%d",&b);		
			if(b==0||b==1){
				insert(root,b);	
			}
			else{
				printf("No not a binary no.\n");
			}
		}
		
		if(a==2){
			printList(root);
			BinaryToDecimal(root);
		}
		if(a==3){
			printf("Exiting from loop\n");
			break;
		}
		
	}
	
	
}
