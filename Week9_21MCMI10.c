#include <stdio.h>
#include<stdlib.h>

struct Queue {
	int front,rear,size;
	unsigned capacity;
	int *q;
};

struct Queue* createQueue(int qSize){
	
	struct Queue* Q=(struct Queue*)malloc(sizeof(struct Queue));
	Q->front=-1;
	Q->rear=-1;
	Q->capacity=qSize;
	Q->q=(int*)malloc(sizeof(int)*qSize);
	
	return Q;
}

int isFull(struct Queue *Q){
	return (Q->rear==Q->capacity-1);
}

int isEmpty(struct Queue *Q){
	return (Q->rear==Q->front);
}


int EnQueue(struct Queue *Q, int data){
	if(isFull(Q)){
		printf("\nQueue is full.");
		return;
	}

	Q->q[++Q->rear]=data;
	return 0;
}

int DeQueue(struct Queue *Q){
	if(isEmpty(Q)){
		printf("\nQueue is empty");
		return;
	}
	return Q->q[++Q->front];	
}
/*
void printQueue(struct Queue *Q){
	int i=Q->front,j=Q->rear;
	i++;
	printf("\n");
	while(i<=j){
		printf("%d ",Q->q[i]);
		i++;
	}
}
*/

/*****************BFS**************/
int BFS_Traversal(int nodeCount, int G[][nodeCount],int V[]){
	
	int i=0,j=0,nodeVisit[nodeCount];   
	printf("Vertices are:-");
	for(i=0;i<nodeCount;i++){
		nodeVisit[i]=0;
		printf("%d ",V[i]);
	}
	
	struct Queue *Q=createQueue(nodeCount);
	EnQueue(Q, V[0]);
	nodeVisit[0]++;
	
	printf("\nBreadth first search:-");
	i=0;
	while(!isEmpty(Q)){ 
		
		for(j=0;j<nodeCount;j++){
			if((G[i][j]>0)&&(nodeVisit[j]==0)){
				EnQueue(Q,V[j]);  
				nodeVisit[j]++;	
			}	
		}
		//printQueue(Q);
		printf("\n");
		
		int temp=DeQueue(Q);
		printf("%d  ",temp);
		
		i++;	
	}	
}

/***************DFS***********/
int nodeVisit[100];
int DFS_Traversal(int nodeCount, int G[nodeCount][nodeCount],int V[]){
	int n;
	for(n=0;n<100;n++){
		nodeVisit[n]=0;
	} 
	
	printf("Depth first traversal:-\n");
		
	for(n=0;n<nodeCount; n++){
		if(nodeVisit[n]==0){
			DFS(nodeCount,G,V,n);
		}
	}
	return;
}

int DFS(int nodeCount, int G[nodeCount][nodeCount],int V[], int start){
	int i;
	printf("%d ",V[start]);
	nodeVisit[start]++;
	for(i=0;i<nodeCount;i++){
		if(G[start][i]&&!nodeVisit[start]){
			DFS(nodeCount, G,V,i);
		}	
	} 	
}

int main(){
	
	int nodeCount;	
	printf("Creating Graph.\n");
	printf("Enter no. of nodes:-\n");
	
	scanf("%d",&nodeCount);
	
	int G[nodeCount][nodeCount], V[nodeCount];
	int i,j;
	for(i=0;i<nodeCount;i++){       
		for(j=0;j<nodeCount;j++){
			G[i][j]=0;              /*Adjacency matrix*/
		}
	}
	int n;
	for(n=0;n<nodeCount;n++){
		V[n]=n;                   /*Vertices*/
	}
	
	printf("Enter pair of vertices having edges seperated with spaces OR enter -1 -1 to end:-\n");
	while(1){
		int i=0,j=0;
		scanf("%d %d",&i,&j);
		if(i==-1||j==-1){
			break;
		}
		if(i>nodeCount||j>nodeCount||i==j){
			printf("""Invalid Input"" Try again.\n");
			continue;
		}
		G[i][j]=1;
		G[j][i]=1;
	}	
/****************************************************************/	
	int G1[8][8];	
	for(i=0;i<nodeCount;i++){       
		for(j=0;j<nodeCount;j++){
			G1[i][j]=0;             
		}
	}
	G1[0][1]=G1[1][0]=1;
	G1[1][2]=G1[2][1]=1;
	G1[1][7]=G1[7][1]=1;
	G1[2][4]=G1[4][2]=1;
	G1[2][3]=G1[3][2]=1;
	G1[4][7]=G1[7][4]=1;
	G1[4][6]=G1[6][4]=1;
	G1[4][5]=G1[5][4]=1;	
/***************************************************************/
	while(1){
		printf("\n Choose option:-\n");
		printf("1) BFS Traversal\n");
		printf("2) DFS Traversal\n");
		printf("3) Exit\n");
		scanf("%d",&n);
		if(n==1){
			BFS_Traversal(nodeCount,G,V);
		}
		if(n==2){
			DFS_Traversal(nodeCount,G1,V);
		}
		else{
			printf("\nInvalid input...Try again\n\n\n");
		}
	}
	return 0;
}
