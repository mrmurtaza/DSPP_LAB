#include <stdio.h>
#include <stdlib.h>
struct node{
	
	int data;
	struct node *next;
	
};

int printList(struct node* last){
	
	struct node* temp=last->next;	
	do{
		
		printf("%d ", temp->data);
		temp=temp->next;//
		
	}while(temp!=last->next);
	printf("\n");
	return 0;	
}


int main(){
	
	struct node *last,*temp;
		last= (struct node*)malloc(sizeof(struct node));
		if(last==NULL){
			printf("Memory Full");
			return 0;
		}	
		last->data=1;
	
	last->next=(struct node*)malloc(sizeof(struct node));
	if(last->next==NULL){
			printf("Memory Full");
			return 0;
		}
	last->next->data=2;
	last->next->next=last;
	last=last->next;
	
	temp =last->next;
	last->next=(struct node*)malloc(sizeof(struct node));
	if(last->next==NULL){
			printf("Memory Full");
			return 0;
		}
	last->next->data=3;
	last->next->next=temp;
	last=last->next;
	
	temp =last->next;
	last->next=(struct node*)malloc(sizeof(struct node));
	if(last->next==NULL){
			printf("Memory Full");
			return 0;
		}
	last->next->data=4;
	last->next->next=temp;
	last=last->next;
	
	temp =last->next;
	last->next=(struct node*)malloc(sizeof(struct node));
	if(last->next==NULL){
			printf("Memory Full");
			return 0;
		}
	last->next->data=5;
	last->next->next=temp;     
	last=last->next;
	
	temp =last->next;
	last->next=(struct node*)malloc(sizeof(struct node));
	if(last->next==NULL){
			printf("Memory Full");
			return 0;
		}
	last->next->data=6;
	last->next->next=temp;
	last=last->next;
	
	temp =last->next;
	last->next=(struct node*)malloc(sizeof(struct node));
	if(last->next==NULL){
			printf("Memory Full");
			return 0;
		}
	last->next->data=7;
	last->next->next=temp;
	last=last->next;
	
	temp =last->next;
	last->next=(struct node*)malloc(sizeof(struct node));
	if(last->next==NULL){
			printf("Memory Full");
			return 0;
		}
	last->next->data=8;
	last->next->next=temp;
	last=last->next;
	
	temp =last->next;
	last->next=(struct node*)malloc(sizeof(struct node));
	if(last->next==NULL){
			printf("Memory Full");
			return 0;
		}
	last->next->data=9;
	last->next->next=temp;
	last=last->next;
	
	temp =last->next;
	last->next=(struct node*)malloc(sizeof(struct node));
	if(last->next==NULL){
			printf("Memory Full");
			return 0;
		}
	last->next->data=10;
	last->next->next=temp;
	last=last->next;
	
	temp =last->next;
	last->next=(struct node*)malloc(sizeof(struct node));
	if(last->next==NULL){
			printf("Memory Full");
			return 0;
		}
	last->next->data=11;
	last->next->next=temp;
	last=last->next;


/***************************************************************************/
	
	
	struct node* counter;
	struct node* slowCounter;
	
	slowCounter=last->next;         
	counter=last->next->next;
	
	while((counter->next!=last)&&(counter->next->next!=last)){
		
		counter=counter->next->next;	
		slowCounter=slowCounter->next;

	}
	
//If odd	
	if(counter->next==last){ 
		struct node* first=last->next;
		slowCounter=slowCounter->next;
	//	counter=last;
		last->next=slowCounter->next;
		slowCounter->next=first;
		printf("Circular List has odd no. of nodes\n");  
	}
	
//if even	
	else if(counter->next->next==last){
		struct node *first=last->next;
		counter=counter->next->next;
		counter->next=slowCounter->next->next;
		slowCounter=slowCounter->next;
		slowCounter->next=first;	
		printf("Circular List has even no. of nodes\n");
		

	}
	printf("First List:- ");
	printList(slowCounter);
	printf("Second List:- ");
	printList(last);

	return 0;
}
