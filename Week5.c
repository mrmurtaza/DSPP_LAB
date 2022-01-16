#include<stdio.h>
#include<stdlib.h>

struct ThTree{
	char *item;
	struct frequency *freq;
	struct ThTree *nextSibling;
	struct ThTree *firstChild;	
};

struct frequency{
	int p;
};

int stringCompare(char *a,char *b)  
{  
   int flag=0;  
    while(*a!='\0' && *b!='\0')  // while loop  
    {  
        if(*a!=*b){  
            flag=1;  
        }  
        a++;  
        b++;  
    }    
    if(flag==0)  
   		return 0;  
    else  
    	return 1;  
}  

int NewCategory(struct ThTree *root, char *category){
	
	struct ThTree *temp=root;
	if(NULL==root->firstChild){
		root->firstChild=(struct ThTree*)malloc(sizeof(struct ThTree));
		temp->firstChild->item=(char*)malloc(20*sizeof(char)+1);
		root->firstChild->item=category;
		root->firstChild->nextSibling=NULL;
		root->firstChild->firstChild=NULL;
		root->firstChild->freq=NULL;
		printf("\n %s inserted as first child\n",category);
	}
	
	else{
		temp=temp->firstChild;
		while(temp->nextSibling){
			temp=temp->nextSibling;
		}
		temp->nextSibling=(struct ThTree*)malloc(sizeof(struct ThTree));
		temp->nextSibling->item=(char*)malloc(20*sizeof(char)+1);
		temp->nextSibling->item=category;
		temp->nextSibling->nextSibling=NULL;
		temp->nextSibling->firstChild=NULL;
		temp->nextSibling->freq=NULL;printf("\n %s inserted as next child\n",category);
	}	
}

int WordInToCategory(struct ThTree *root, int j, char *word){
	
	struct ThTree* temp=root->firstChild;
	char *w=word;

/*Finding the particular category*/
	while(j>1){
		temp=temp->nextSibling;
		j--;
	}
	if(temp==NULL){
		printf("This Category not found.");
		return 0;
	}
	
/*Finding if the word already exist*/	
	if(NULL==temp->firstChild){
		temp->firstChild=(struct ThTree*)malloc(sizeof(struct ThTree));
		temp->firstChild->item=(char*)malloc(20*sizeof(char)+1);
		temp->firstChild->item=word;
		temp->firstChild->nextSibling=NULL;
		temp->firstChild->firstChild=NULL;
		temp->firstChild->freq=NULL;
		printf("\n' %s ' added as New Word",temp->firstChild->item);
		return 0;	
	}
	else if(0==stringCompare(temp->firstChild->item,word)){
	//	temp->firstChild->frequency++;
		
		if(temp->firstChild->freq==NULL){
			temp->firstChild->freq=(struct frequency*)malloc(sizeof(struct frequency));
			temp->firstChild->freq->p=2;	
		}
		else{
			temp->firstChild->freq->p++;
		}
		printf("\n' %s ' added as Existing Word",temp->firstChild->item);
		return 0;
	}

	temp=temp->firstChild;
	while(1){
		
		if(NULL==temp->nextSibling){
			break;
		}
		if(w==temp->nextSibling->item){
			break;
		}
		temp=temp->nextSibling;
	}
	if(NULL==temp->nextSibling){
		temp->nextSibling=(struct ThTree*)malloc(sizeof(struct ThTree));
		temp->nextSibling->item=(char*)malloc(20*sizeof(char)+1);
		temp->nextSibling->item=word;
		temp->nextSibling->nextSibling=NULL;
		temp->nextSibling->firstChild=NULL;
		temp->nextSibling->freq=NULL;
		printf("\n' %s ' added as New Word",temp->nextSibling->item);
	}
	else{
	//	temp->nextSibling->frequency++;
		if(temp->nextSibling->freq==NULL){
			temp->nextSibling->freq=(struct frequency*)malloc(sizeof(struct frequency));
			temp->nextSibling->freq->p=2;	
		}
		else{
			temp->nextSibling->freq->p++;
		}
		printf("\n' %s ' added as Existing Word",temp->nextSibling->item);
	}
}


int PrintThTree(struct ThTree *root,int a){
	
	if(!root){
		return 1;
	}
	printf(" %d->%s ",a, root->item);
    PrintThTree(root->nextSibling,a+1);
}

int PrintAllWords(struct ThTree *root){
	struct ThTree *temp= root->firstChild;
	struct ThTree *wordCounter=root->firstChild;
	
	while(temp){
		wordCounter=temp;
		printf("\n%s :-", temp->item);
		if(wordCounter->firstChild){
			wordCounter=wordCounter->firstChild;
			while(wordCounter){	
			
				if(wordCounter->freq!=NULL){
					printf("%s (%d) ",wordCounter->item,wordCounter->freq->p);
				}
				else{
					printf("%s (1) ",wordCounter->item);
				}
				wordCounter=wordCounter->nextSibling;	
			}
		}
		temp=temp->nextSibling;
	}	
}


int DegreeOfNodes(struct ThTree *root, char *word){
	struct ThTree *temp= root->firstChild;
	struct ThTree *wordCounter=root->firstChild;
	int i,j=0;
	while(temp){
		wordCounter=temp;
		i=0;
		if(stringCompare(temp->item,word)==0){
			printf("\nDegree of node ' %s ' is",temp->item);
		}
		if(wordCounter->firstChild){
			wordCounter=wordCounter->firstChild;
			while(wordCounter){	
			
				if(stringCompare(wordCounter->item,word)==0){
					printf("\nDegree of node ' %s ' is ",wordCounter->item);
					if(wordCounter->freq!=NULL){
						printf("1");
					}
					else{
						printf("0");
					}
				}
			
				if(wordCounter->freq!=NULL){
					i=i+wordCounter->freq->p;
				}
				else{
					i++;
				}
				wordCounter=wordCounter->nextSibling;
			}
			if(stringCompare(temp->item,word)==0){
				printf(" %d\n",i);
			}
		}
		temp=temp->nextSibling;
		j++;
	}	
}



int PrintWordFrequencyWise(struct ThTree *root){
	struct ThTree *temp= root->firstChild;
	struct ThTree *wordCounter=root->firstChild;
	
	char *words[80];
	int freq[80];
	int i=0;

	while(temp){
		wordCounter=temp;
		if(wordCounter->firstChild){
			wordCounter=wordCounter->firstChild;
			while(wordCounter){	
				words[i]=wordCounter->item;	
				if(wordCounter->freq!=NULL){
					freq[i]=wordCounter->freq->p;
				}
				else{
					freq[i]=1;
				}
				i++;		
				wordCounter=wordCounter->nextSibling;
			}
		}
		temp=temp->nextSibling;
	}
	
	
	i--;
	int j=i,k=i,max,MaxIndex;
	while(i>=0){
		j=k;
		max=0;
		MaxIndex=0;
		while(j>=0){
			if(freq[j]>max){
				MaxIndex=j;
				max=freq[j];
			}
			j--;
		}
		printf(" %s (%d)\n",words[MaxIndex],freq[MaxIndex]);
		freq[MaxIndex]=0;
		i--;

	}	
}



int DepthOfNode(struct ThTree *root, char *word){
	struct ThTree *temp= root->firstChild;
	struct ThTree *wordCounter=root->firstChild;
	if(stringCompare(root->item,word)==0){
		printf("\nDepth of node ' %s ' is 0",root->item);
		return 0;
	}
	while(temp){
		wordCounter=temp;
		if(stringCompare(temp->item,word)==0){
			printf("\nDepth of node ' %s ' is 1",temp->item);
			return 0;
		}
		if(wordCounter->firstChild){
			wordCounter=wordCounter->firstChild;
			while(wordCounter){	
				if(stringCompare(wordCounter->item,word)==0){
					printf("\nDepth of node ' %s ' is 2",wordCounter->item);
					return 0;
				}
				wordCounter=wordCounter->nextSibling;
			}
		}
		temp=temp->nextSibling;
	}
	printf("Node not found.");	
}



int main(){
	/*Root of tree*/
	struct ThTree *root=(struct ThTree*)malloc(sizeof(struct ThTree));
	root->item=(char*)malloc(20*sizeof(char)+1);
	root->item="Word";
	root->firstChild=NULL;
	root->nextSibling=NULL;
	root->freq=NULL;
	
	/*Inserting nodes manually in the tree just for demonstration*/
	char *w=(char*)malloc(20*sizeof(char)+1);
	w="Physical Activity";
	NewCategory(root,w);
	w="Education";
	NewCategory(root,w);
	w="Food";
	NewCategory(root,w);
	w="Work";
	NewCategory(root,w);
	w="Hobby";
	NewCategory(root,w);
	w="Family";
	NewCategory(root,w);
	w="Worship";
	NewCategory(root,w);
	printf("\nPrinting all existing categories:-\n");
	PrintThTree(root->firstChild,1);
	
	w="Exercise";
	WordInToCategory(root,1,w);
	w="Exercise";
	WordInToCategory(root,1,w);
	w="Exercise";
	WordInToCategory(root,1,w);
	
	w="God";
	WordInToCategory(root,7,w);
	
	w="Book";
	WordInToCategory(root,2,w);
	w="Book";
	WordInToCategory(root,2,w);
	w="Book";
	WordInToCategory(root,2,w);
	w="Book";
	WordInToCategory(root,2,w);
	w="Book";
	WordInToCategory(root,2,w);
	w="Book";
	WordInToCategory(root,2,w);
	w="Book";	
	WordInToCategory(root,2,w);
	
	w="Relative";
	WordInToCategory(root,6,w);
	w="Relative";
	WordInToCategory(root,6,w);
	w="Relative";
	WordInToCategory(root,6,w);
	
	w="Lunch";
	WordInToCategory(root,3,w);
	w="Lunch";
	WordInToCategory(root,3,w);
	w="Lunch";
	WordInToCategory(root,3,w);
	w="Lunch";
	WordInToCategory(root,3,w);
	w="Lunch";
	WordInToCategory(root,3,w);
	
	w="Gardening";
	WordInToCategory(root,5,w);
	w="Gardening";
	WordInToCategory(root,5,w);
	
	w="Meeting";
	WordInToCategory(root,4,w);
	w="Prayer";
	WordInToCategory(root,7,w);
	
	w="Football";
	WordInToCategory(root,1,w);
	w="Football";
	WordInToCategory(root,1,w);
	
	w="Studying";
	WordInToCategory(root,2,w);
	w="Studying";
	WordInToCategory(root,2,w);
	w="Studying";	
	WordInToCategory(root,2,w);
	
	w="Class";
	WordInToCategory(root,2,w);
	w="Class";
	WordInToCategory(root,2,w);
	w="Class";
	WordInToCategory(root,2,w);
	w="Class";
	WordInToCategory(root,2,w);
	w="Class";
	WordInToCategory(root,2,w);
	w="Class";
	WordInToCategory(root,2,w);
	
	w="Book reading";
	WordInToCategory(root,5,w);
	w="Book reading";
	WordInToCategory(root,5,w);
	w="Book reading";
	WordInToCategory(root,5,w);
	w="Book reading";
	WordInToCategory(root,5,w);
	
	w="Story Telling";
	WordInToCategory(root,5,w);
	
	w="Assignment";
	WordInToCategory(root,2,w);
	
	w="Daughter";
	WordInToCategory(root,6,w);
	w="Daughter";
	WordInToCategory(root,6,w);
	
	w="Cake";
	WordInToCategory(root,3,w);
	
	w="Project";
	WordInToCategory(root,4,w);
	w="Project";
	WordInToCategory(root,4,w);
	w="Project";
	WordInToCategory(root,4,w);
	w="Project";
	WordInToCategory(root,4,w);
	w="Project";
	WordInToCategory(root,4,w);
	w="Project";
	WordInToCategory(root,4,w);
	w="Project";
	WordInToCategory(root,4,w);
	w="Project";
	WordInToCategory(root,4,w);
	w="Project";
	WordInToCategory(root,4,w);
	w="Project";
	WordInToCategory(root,4,w);

	printf("\n*************************************************************\n");
	printf("Printing all the words category wise:-\n");
	PrintAllWords(root);
	
	w="Work";
	DegreeOfNodes(root,w);
	
	
/*Menu driven program*/	
	

	int i=0;
	while(1){
		printf("\n*************************************************************\n");
		printf("\n\nChoose option:-\n");
		printf("1:- Insert New Category.\n");
		printf("2:- Insert New item in existing Category.\n");
		printf("3:- Print all the categories.\n");
		printf("4:- Print all the words and their frequency\n");
		printf("5:- Print degree of any node.\n");
		printf("6:- Print all words frequency wise.\n");
		printf("7:- Print depth of any node.\n");
		printf("8:- Exit.\n");
		printf("\n*************************************************************\n");
		scanf("%d",&i);
		char *s=(char*)malloc(20*sizeof(char)+1);
		
		if(i==1){
			//Insert in new category
			char *category=(char*)malloc(20*sizeof(char)+1);;
			printf("Enter new Category:-\n");
			scanf("%s",category);
			NewCategory(root, category);
		}
		
		else if(i==2){
			printf("Choose from existing category:-\n");
			//Print existing categories
			PrintThTree(root->firstChild,1);
			int j;
		//	char *s=(char*)malloc(20*sizeof(char)+1);
			scanf("%d",&j);
			printf("Enter the Word:- ");
			scanf("%s",s);
			WordInToCategory(root, j,s);
		}
		else if(i==3){
			printf("Printing all categories:- ");
			PrintThTree(root->firstChild,1);
		}
		else if(i==4){
			PrintAllWords(root);
		}
		else if(i==5){
			printf("Enter the node:- ");
			scanf("%s",s);
			DegreeOfNodes(root,s);
		}
		else if(i==6){
			printf("Printing words according to their frequencies:-\n");
			PrintWordFrequencyWise(root);
		}
		else if(i==7){
			printf("Enter node:-");
			scanf("%s",s);
			DepthOfNode(root,s);
		}
		else if(i==8){
			break;
		}	
		printf("\n");		
	}	
}
