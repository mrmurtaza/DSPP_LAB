#include<stdio.h>
#include<stdlib.h>
//#define INT_MIN 99999
int Hash(int tsize, int v){
	return v%tsize;
}
int power(int i, int x){
	int y=i;
	while(x>0){
		i=i*y;
		x--;
	}
	return i;
}
int Insert(int table[],int tsize, int v){
	tsize--;
	if(table[v%tsize]==INT_MIN){
		table[v%tsize]=v;
		printf("\n%d is inserted at %dth position\n",v,v%tsize);
		return 0;
	}
	
	int i=0;
	int index;
	while(i<tsize){
		i++;
		//index=(v+(i)^2)%tsize;
		index=(Hash(tsize,v)+i-Hash(i,v))%tsize;
		if(table[index]==INT_MIN){
			table[index]=v;
			printf("\n%d is inserted at %dth position\n",v,index);
			return 0;
		}	
	}
	if(table[index]!=INT_MIN){
		printf("Key can't be inserted");
	}
	return 0;	
}

int Delete(int table[],int tsize, int v){
	tsize--;
	int i=-1;
	int index;
	while(i<20){
		index=(Hash(tsize,v)+i-Hash(i,v))%tsize;
		i++;
		if(table[index]==v){
			table[index]=INT_MIN;
			break;	
		}	
	}
	if(table[index]==INT_MIN){
		printf("Key can't delete");
	}
	return 0;	
}

int Search(int table[], int tsize, int v){
	tsize--;
	int i=-1,index;
	while(i<20){
		i++;
		index=(Hash(tsize,v)+i-Hash(i,v))%tsize;
		if(table[index]==v){
		//	table[(v+(i)^2)%tsize]=INT_MIN;
			break;	
		}	
	}
	if(table[index]==INT_MIN){
		printf("Key can't find the key");
		return 0;
	}
	printf("Key for %d is %d ",v,index);
	return 0;	
}

int LoadFactor(int table[], int tsize){
	int count=0,i=0;
	while(i<tsize){
		if(table[i]!=INT_MIN){
			count++; //printf("One found");
		}
		i++;
	}
	float lf=(float)count/tsize;
	printf("Load Factor of the table is:- %f\n", lf);
	return 0;
}



int main(){
	int table[50],c,k,i=0,n=50;
//	printf("%d", INT_MIN);
	while(i<n){
		table[i]=INT_MIN;
		i++;
	}
	
	while(1){
		printf("Enter choice:\n");
		printf("1) Insert a key\n");
		printf("2) Delete a key\n");
		printf("3) Search a key using key value\n");
		printf("4) Calculate Load Factor\n");
		printf("5) Print table\n");
		printf("6) Exit\n");
		scanf("%d",&c);
		
		if(c==1){
			printf("Enter a key to insert\n");
			scanf("%d", &k);
			Insert(table,n,k);
		}
		
		if(c==2){
			printf("Enter the key to delete\n");
			scanf("%d",&k);
			Delete(table,n,k); 
		}
		
		if(c==3){
			printf("Enter the key to search\n");
			scanf("%d",&k);
			Search(table,n,k);
		}
		
		if(c==4){
			LoadFactor(table,n);
		}
		
		if(c==5){
			i=0;
			while(i<n){		
				if(table[i]!=INT_MIN){
					printf("%d \n",table[i]);
				}
				i++;
			}
			printf("\n");
		}
	
		if(c==6){
			break;
		}
		
	}
}
