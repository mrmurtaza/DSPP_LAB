#include<stdio.h>
#include<stdlib.h>

struct Stack{
	int top;
	unsigned capacity;
	int* array;
};

struct Stack* createStack(unsigned capacity)
{
	struct Stack* stack= (struct Stack*)malloc(sizeof(struct Stack));
	stack->capacity=capacity;
	stack->top=-1;
	stack->array=(int*)malloc(stack->capacity*sizeof(int));
	return stack;
}

int isFull(struct Stack* stack)
{
	return stack->top==stack->capacity-1;
}

int isEmpty(struct Stack* stack){
	return stack->top==-1;
}

void push(struct Stack* stack, int item){
	if(isFull(stack)){
		return;
	}
	
	stack->array[++stack->top]=item;
	printf("%d pushed to stack\n", item);
	
}

int pop(struct Stack* stack){
	if (isEmpty(stack))
		return INT_MIN;
	return stack->array[stack->top--]; 
}

void display(struct Stack* stack){
	int i=stack->top;
	printf("\n \nStack elements are as follow\n" );
	while(i > -1){
		printf("%d\n", stack->array[i]);
		i--;
	}
}


int main(){
	struct Stack* stack = createStack(20);
	
	printf("%d popped from stack \n", pop(stack));
	push(stack, 10);
	push(stack, 20);
	push(stack, 30);
	push(stack, 40);
	push(stack, 50);
	
	printf("%d popped from stack", pop(stack));
	
	display(stack);

	
	return 0;
}
