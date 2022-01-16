#include <stdio.h>
#include <stdlib.h>

struct btree{
	int data;
	struct btree *left;
	struct btree *right;	
};

struct Queue{
	int front;
	int rear;
	struct btree *queue[50];	
};

int EnQueue(struct btree *node,struct Queue *Q){

	if(Q->rear==19){
		printf("Queue is full.");
		return 0;
	}
	Q->queue[++Q->rear]=node; 
	return 0;
}

struct btree* DeQueue(struct Queue *Q){
	
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


struct btree* newNode(int item)
{
    struct btree* temp
        = (struct btree*)malloc(sizeof(struct btree));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
struct btree* insert(struct btree* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL)
        return newNode(key);
 
    /* Otherwise, recur down the tree */
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
 
    /* return the (unchanged) node pointer */
    return node;
}


struct btree* minValueNode(struct btree* node)
{
    struct btree* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}
 

struct btree* deleteNode(struct btree* root, int key)
{
    // base case
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
 
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
 
    else {
        // node with only one child or no child
        if (root->left == NULL) {
            struct btree* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct btree* temp = root->left;
            free(root);
            return temp;
        }
 
        // (smallest in the right subtree)
        struct btree* temp = minValueNode(root->right);
 
        // Copy the inorder
        // successor's content to this node
        root->data = temp->data;
 
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int printTree(struct btree *root){
	
	if(!root){
		return 0;
	}
	printTree(root->left);
	printf(" %d ",root->data);
	printTree(root->right);
	
	return 0;
}

void printCurrentLevel(struct btree* root, int level);
int height(struct btree* node);
struct btree* newNode(int data);

void printLevelOrder(struct btree* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}
 
/* Print nodes at a current level */
void printCurrentLevel(struct btree* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}
 
int height(struct btree* node)
{
    if (node == NULL)
        return 0;
    else {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);
 
        /* use the larger one */
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}

void leafSum(struct btree *root, int *sum){ 
    if (!root) 
        return; 
  
    // add root data to sum if  
    // root is a leaf node 
    if (!root->left && !root->right) 
        *sum += root->data; 
   
    leafSum(root->left, sum); 
    leafSum(root->right, sum); 
} 

int nonleaf(struct btree* root){
   if (root == NULL || (root->left == NULL && root->right == NULL)){
      return 0;
   }
   return 1 + nonleaf(root->left) + nonleaf(root->right);
}

int main(){
	
	struct btree *root=(struct btree*)malloc(sizeof(struct btree));
	root->left=NULL;
	root->right=NULL;  
	root->data=10;
	
	insert(root,8);
	insert(root,20);
	insert(root,5);
	insert(root,9);
	insert(root,15);
	insert(root,30);
	insert(root,90);
	
	deleteNode(root,90);
	
	printf("\nPrinting the tree inorder:\n");
	printTree(root);

	printf("\n\nPrinting the tree level wise:\n");
	printLevelOrder(root);
	
	int sum=0;
	leafSum(root, &sum);
	printf("\n\nLeaf nodes sum:- %d", sum);
	
	printf("\n\nNon-leaf nodes sum:- %d", nonleaf(root));
	
	return 0;
	
}
