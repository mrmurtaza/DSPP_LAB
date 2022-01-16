#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <vector>

void MergeSortedIntervals(std::vector<int>& v, int s, int m, int e) {
	

	std::vector<int> temp;

	int i, j;
	i = s;
	j = m + 1;

	while (i <= m && j <= e) {

		if (v[i] <= v[j]) {
			temp.push_back(v[i]);
			++i;
		}
		else {
			temp.push_back(v[j]);
			++j;
		}

	}

	while (i <= m) {
		temp.push_back(v[i]);
		++i;
	}

	while (j <= e) {
		temp.push_back(v[j]);
		++j;
	}

	for (int i = s; i <= e; ++i)
		v[i] = temp[i - s];

}

void Merge_Sort(std::vector<int>& v, int s, int e) {
	if (s < e) {
		int m = (s + e) / 2;
		Merge_Sort(v, s, m);
		Merge_Sort(v, m + 1, e);
		MergeSortedIntervals(v, s, m, e);
	}
}

void printArray(std::vector<int>& arr, int size)
{
	int i,j=1;
	for (i = 0; i < size; i++){
		printf("%d ", arr[i]);
		if(j==10){
			printf("\n");
			j=0;	
		}
		j++;  
    }    
}

void swapArray(std::vector<int>& arr,int n){
	int i=0,temp;
	n=n-1;
	
	while(i<n/100){
		temp=arr[i];
		arr[i]=arr[n-i];
		arr[n-i]=temp;
		i++;
	}	
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

/* Driver code */
int main()
{
	int n=10000,i;
	printf("Enter array size:-\n");
	scanf("%d",&n);
	int left=0,right=n-1;
	std::vector<int> A(n);
	for(i = 0; i<n; i++){
		A[i]=rand();
	}


	/*Merge Sort*/
	//Random array.
	clock_t t;
	t=clock();
    Merge_Sort(A,left,right);
    t=clock()-t;
    double time_taken=((double)t)/CLOCKS_PER_SEC;
    printf("Time taken by Merge_Sort on random array %f\n",time_taken);
    
    
    //Sorted array.
	t=clock();
    Merge_Sort(A,left,right);
    t=clock()-t;
    time_taken=((double)t)/CLOCKS_PER_SEC;
    printf("Time taken by Merge_Sort on sorted array %f\n",time_taken);
    
    
    //Almost sorted array.
    swapArray(A,n);
    t=clock();
    Merge_Sort(A,left,right);
    t=clock()-t;
    time_taken=((double)t)/CLOCKS_PER_SEC;
    printf("Time taken by Merge_Sort on almost sorted array %f\n\n",time_taken);  
 
    
    
    
 //printArray(A,n);
	return 0;
}

