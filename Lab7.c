#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Merge(int A[],int temp[], int left,int mid,int right){
	int i,left_end,size,temp_pos;
	left_end=mid+1;
	temp_pos=left;
	size=right-left+1;
	while((left<=left_end)&&(mid<=right)){
		if(A[left]<=A[mid]){
			temp[temp_pos]=A[left];
			temp_pos=temp_pos+1;
			left=left+1;
		}
		else{
			temp[temp_pos]=A[mid];
			temp_pos=temp_pos +1;
			mid=mid+1;
		}
	}
	
	while(left<=left_end){
		temp[temp_pos]=A[left];
		left=left+1;
		temp_pos=temp_pos+1;
	}
	
	while(mid<=right){
		temp[temp_pos]=A[mid];
		mid=mid+1;
		temp_pos=temp_pos+1;
	}
	
	for(i=0;i<=size;i++){
		A[right]=temp[right];
		right=right+1;
	}	
}

void Merge_Sort(int A[],int temp[],int left, int right){
	int mid;
	if(right>left){
		mid=(right+left)/2;
		Merge_Sort(A,temp,left,mid);
		Merge_Sort(A,temp,mid+1,right);
		Merge(A,temp,left,mid+1,right);
	}
}

int main(){
	int A[1000],i,n;
	printf("Enter size of the array:\n");
	scanf("%d",&n);
	int left=0,right=1000-1;
	for(i = 0; i<1000; i++){
		A[i]=rand();
	//	printf("%d\n",A[i]);
	}
	
	clock_t t;
//	t=clock();
   Merge_Sort(A,0,left,right);
 //   t=clock()-t;
    
 //   double time_taken=((double)t)/CLOCKS_PER_SEC;
 //   printf("Time taken by Merge_Sort is %f\n",time_taken);
      printf("Enter size of the array:\n");
}



