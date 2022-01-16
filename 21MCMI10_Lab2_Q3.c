#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node{
	char *info1;
	char *info2;
	char *info3;
	struct node* link;
};


/*int insert(struct node *root,char *a,char *b,char *c){
	
	struct node *newNode=(struct node*)malloc(sizeof(struct node));
//	char *a;
	struct node *temp=root;
	while(temp->link!=NULL){
		temp=temp->link;
	}
	
	temp->link =newNode;
	newNode->link=NULL;
//	scanf("%s",&a);
	newNode->info1=a;
//	scanf("%s",&a);
	newNode->info2=b;
//	scanf("%s",&a);
	newNode->info3=c;
	
	printf("New node info are: %s, %s, %s",newNode->info1,newNode->info2,newNode->info3);

	return 0;
}*/


int display(struct node *root){
	
	struct node *temp=root;
	printf("Node List:- ");
	while(temp!=NULL){
		printf(" %s ",temp->info2);
		temp=temp->link;
	}
	
	temp=root;
	int i=0;
	while(temp->link!=NULL){
		
		while((temp->info3[i]!='\0')||(temp->link->info1[i]!='\0')){
			if(temp->info3[i]!=temp->link->info1[i]){
				printf("\nString not match");
				return 0;
			}
			i++;
		}
		temp=temp->link;
	}	
}


int ManualInsert(struct node *root, char *a, char *b, char *c){
	
	struct node *newNode=(struct node*)malloc(sizeof(struct node));
	struct node *temp=root;
	while(temp->link!=NULL){
		temp=temp->link; 
	}//printf("Reached outside...");
	temp->link=newNode;
	newNode->link=NULL;
	newNode->info1=a;
	newNode->info2=b;
	newNode->info3=c;
	return 0;
}

int main(){
	
	struct node *root=(struct node*)malloc(sizeof(struct node));
	root->link=NULL;
	root->info1="blue";
	root->info2="red";
	root->info3="green";
	
	ManualInsert(root,"green","black","yellow");
	ManualInsert(root,"yellow","white","orange");
	ManualInsert(root,"orange","grey","voilet");
	ManualInsert(root,"voilet","brown","blue");

	
	while(1){
		
		printf("\nEnter option:\n");
		printf("1) Insert new node\n");
		printf("2) Display list\n");
		printf("3) Replace first string of 1st & 5th node with 'color'\n");
		printf("4) Exit\n");
		int a;
		scanf("%d",&a);
		
		if(a==1){
			char a[10], b[10], c[10];
			printf("Enter all 3 info: \n");
			scanf("%s",a);
			scanf("%s",b);
			scanf("%s",c);

			ManualInsert(root,a,b,c);	
		}
		
		if(a==2){
			display(root);
		}
		if(a==3){
			root->info1="color";
			int i=0;
			struct node *temp=root;
			temp=temp->link->link->link->link;
			temp->info1="color";
		//	printf("....%s....",temp->info2);
			display(root);
		}
		if(a==4){
			printf("Exiting from loop\n");
			break;
		}
		else{
			break;
		}
		
	}
	
	
}
