#include<stdio.h>
#include<stdlib.h>

struct Stack{
	int item;
	struct Stack* next;
};

struct Stack* newNode(int item){
	struct Stack* stackNode=(struct Stack*)malloc(sizeof(struct Stack));
	stackNode->item=item;
	stackNode->next=NULL;
	return stackNode;
}

int isEmpty(struct Stack* root){
	return !root;
}

void push(struct Stack** root, int item)
{
    struct Stack* stack = newNode(item);
    stack->next = *root;
    *root = stack;
    printf("%d pushed to stack\n", item);
}
 
int pop(struct Stack** root)
{
    if (isEmpty(*root))
        return INT_MIN;
    struct Stack* temp = *root;
    *root = (*root)->next;
    int popped = temp->item;
    free(temp);
 
    return popped;
}

void display(struct Stack* stack)
{	struct Stack* i=stack      ;
	while(i!=NULL){
		printf("\n%d",stack->item);
		i=i->next;
	}
}

int main()
{
    struct Stack* root = NULL;
 
    push(&root, 20);
    push(&root, 30);
 
    printf("%d popped from stack\n", pop(&root));
	
	display(root);

 
    return 0;
}
