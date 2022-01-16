
#include <stdio.h>
#include <stdlib.h>

struct Node
{
int data;
struct Node *next;
};

/* inserts a new node on the front of the list. */
void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->data = new_data;

	new_node->next = (*head_ref);

	(*head_ref) = new_node;
}

/* insert a new node after the given prev_node */
void insertAfter(struct Node* head, int position)
{	
struct Node *temp=head;
int i=0;
	while(i<position){
		temp=temp->next;
	}
	
	struct Node* holder=temp->next;
	struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));
	temp->next=new_node;
	new_node->next=holder;
	printf("Enter data:-");
	scanf("%d",&i);
	new_node->data = i;

}

/* appends a new node at the end */
void append(struct Node** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

	struct Node *last = *head_ref;

	new_node->data = new_data;
	new_node->next = NULL;
	if (*head_ref == NULL)
	{
	*head_ref = new_node;
	return;
	}

	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return;
}

// function prints contents of linked list starting from head
void printList(struct Node *node)
{
while (node != NULL)
{
	printf(" %d ", node->data);
	node = node->next;
}
}


int deleteByPosition(struct Node *head, int p){
	if(p==1){
		int i;
		head->data=head->next->data;
		head->next=head->next->next;
		return 0;
	}
	struct Node *temp=head;
	int i=0;
	while(p-1>i){
		temp=temp->next;
	}
	struct Node *holder=temp->next;
	temp->next=temp->next->next;
	free(holder);	
}

int deleteByValue(struct Node* head,int v){
	
	if(head->data==v){
		int i;
		head->next=head->next->next;
		head->data=head->next->data;
		return 0;
	}
	struct Node *temp=head;
	while(temp){
		if(temp->next->data==v){
			temp=temp->next;
			break;
		}	
	}
	if(temp==NULL){
		printf("No node with give value found");
	}
//	struct Node *holder=temp->next;
	temp->next=temp->next->next;
//	free(holder);
}

int printReverse(struct Node *head){
	
	struct Node *temp=head;
	int a[100],i=0;
	while(temp){
		a[i]=temp->data;
		temp=temp->next;
		i++;
	}
	while(i>0){
		i--;
		printf("%d ",a[i]);
	}
	
}



int main()
{
/* Start with the empty list */
struct Node* head = NULL;

append(&head, 6);

push(&head, 7);

push(&head, 1);

append(&head, 4);

//insertAfter(head->next, 8);

printf("\n Created Linked list is: ");
printList(head);

while(1){
	printf("Enter a choice:-\n");
	printf("1) Insert\n");
	printf("2) Deletion\n");
	printf("3) Display the linked list\n");
	printf("4) Reverse the linked list\n");
	printf("5) Exit\n");
	int c;
	scanf("%d",&c);
	
	if(c==1){
		printf("1) Insert at begining\n");
		printf("2) Insert at end\n");
		printf("3) Insert at a Position\n");
		int d;
		scanf("%d",&d);
		printf("Enter node:-");
		int n;
		scanf("%d",&n);
		if(d==1){
			
			push(&head,n);
		}
		if(d==2){
		
			push(&head,n);
		}
		if(d==3){
			printf("Enter node position:-");
			int p;
			scanf("%d",&p);
			insertAfter(head, p);
		}
	}
	if(c==2){
		printf("Enter choice:-\n");
		printf("1) Delete by position\n");
		printf("2) Delete by value\n");
		int q;
		scanf("%d",&q);
		if(q==1){
		//	delete by position
			printf("Enter node position:-");
			int p;
			scanf("%d",&p);
			deleteByPosition(head,p);
		}
		if(q==2){
		//	delete by value
			printf("Enter node value:-");
			int p;
			scanf("%d",&p);
			deleteByValue(head,p);
		}
	}
	if(c==3){
		printList(head);
	}
	if(c==4){
		//prinf reverse list
		printReverse(head);
	}
	if(c==5){
		break;
	}	
}
return 0;
}

