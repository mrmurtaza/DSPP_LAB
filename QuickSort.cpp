// Quick Sort in c++

#include <iostream>  
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

using namespace std;


int partition(vector<long unsigned int> & a, int start, int end,int pi) {
  unsigned int pivot = pi;
  unsigned int from_left = start+1;
  unsigned int from_right = end;
  unsigned int tmp;
  
  

  	if(pivot==1){
  		 pivot = a[end];}
 	if(pivot==2){
  		//int pivotIndex=start+rand()%(end-start-1);
  		 pivot=a[start];}
  	if(pivot==3){
	  	if(a[start]<a[end]&&a[start]>a[end/2]){
		  pivot=a[start];}
		if(a[end]<a[start]&&a[end]>a[end/2]){
			 pivot=a[end];}
		if(a[end/2]<a[end]&&a[end/2]>a[start]){
			 pivot=a[end/2];}
   }
   if(pivot==4){
  		int l=end/4,h=3*(end/4),m=end/2;
  		if(a[l]<a[h]&&a[l]>a[m]){
  			 pivot=a[l];}
		if(a[h]<a[l]&&a[h]>a[m]){
			 pivot=a[h];}
		if(a[m]<a[h]&&a[m]>a[l]){
			 pivot=a[m];}pivot=a[l];
  }
  
  while (from_left != from_right) {
    if (a[from_left]  <= pivot) 
		from_left++;
    else {
      while (( from_left != from_right)  && (pivot < a[from_right])) 
	  	from_right--;
      tmp =  a[from_right];
      a[from_right] = a[from_left];
      a[from_left] = tmp;
    }
  }
  
  if (a[from_left]>pivot) from_left--;
  a[start] = a[from_left];
  a[from_left] = pivot;

  return (from_left);
}


void Quick_Sort(vector <long unsigned int> & a, int p, int r,int pi) {
  if (p < r) {
    int q = partition(a, p, r,pi);
    Quick_Sort(a, p, q - 1,pi);
    Quick_Sort(a, q + 1, r,pi);
  }
}


int randomize(vector <long unsigned int> & a ,int n){
	
	int temp,i=0;
	while(n/100>i){
		temp=a[i];
		a[i]=a[n-i-1];
		a[n-i-1]=temp;i++;
	}
	return 0;
}



int main() {  

	int s;
	printf("Enter size of array:-");
	scanf("%d",&s);
    vector<long unsigned int> a(s);

    for (long unsigned int i=0; i<s; i++) {
  		a[i] = rand()%(s*10);
  	//	printf("%d ",a[i]);
    }
  	
	printf("Choose one:-\n");
	printf("1) Pivot-1\n");
	printf("2) Pivot-2\n");
	printf("3) Pivot-3\n");
	printf("4) Pivot-4\n");
	int pi=1;
	scanf("%d",&pi);

	printf("Choose one:-\n");
	printf("1) Random array\n");
	printf("2) Almost sorted array\n");
	printf("3) Sorted array\n");
	int c=1;
	scanf("%d",&c);
	
	if(c==2){
		randomize(a,s);
	}
	if(c==3){
		Quick_Sort(a, 0, s-1,1);	
	}

    clock_t t=clock();
    Quick_Sort(a, 0, s-1,pi);
    t=clock()-t;
    clock_t time_taken=((double)t)/CLOCKS_PER_SEC;
    printf("Time taken by Quick_Sort on first element as pivot %f\n",time_taken);
  //print_all (a);
  return 0;
}
