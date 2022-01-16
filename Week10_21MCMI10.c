#include <stdio.h>  
  
int maxElement(int array[], int n) {  
   int i,m=array[0];  
   for(i = 1; i<n; i++) {  
      if(array[i]>m)  
         m=array[i];  
   }  
   return m;
}  
  
void countingSort(int array[], int n, int place) 
{  
  int i,output[n+1],count[10]={0};     
  for (i=0; i<n; i++)  
    count[(array[i]/place)%10]++;  
    
  for (i=1; i<10; i++)  
    count[i]+=count[i-1];  
  
  for (i=n-1; i>=0; i--) {  
    output[count[(array[i]/place) % 10]-1]=array[i];  
    count[(array[i]/place)%10]--;  
  }  
  for (i=0; i<n; i++)  
    array[i]=output[i];  
}  
  
void radixSort(int array[], int n) {  

    int place,max = maxElement(array, n);  
    
    for (place = 1; max/place > 0; place=place*10)  {
    	countingSort(array, n, place);
	}
      
}  
  
void printArray(int array[], int n) {  
	
	int i;
	for (i=0; i<n; ++i) {  
		printf("%d  ", array[i]);  
	}  
	printf("\n");  
}  
  
int main() {  
	
	int n,i=0;
	printf("Enter no. elements:-\n ");
	scanf("%d",&n);
	int array[n];
	while(i<n){
		printf("\nEnter element no. %d :- ",i+1);
		scanf("%d",&array[i]);
		i++;
	}

	radixSort(array, n);
	printf("Sorted array:-\n");
	printArray(array, n);
}  
