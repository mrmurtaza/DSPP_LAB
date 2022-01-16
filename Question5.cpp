
#include<stdio.h>
#include<stdlib.h>

	void minSubArray(int arrA[], int x) {
		int start = 0;
		int ansEnd = 0;
		int ansStart = 0;
		int currSum = 0;
		int minLen = sizeof(arrA);
		int found = -1;
		for (int i = 0; i <= sizeof(arrA); i++) {
			while (currSum >= x) {
			    found = true;
			    currSum = currSum - arrA[start];
				if (i - start <= minLen) {
					minLen = (i - start);
					ansEnd = i;
					ansStart = start;
				}
					
				start++;
			}
			if (i < sizeof(arrA)) {
				currSum = currSum + arrA[i];
			}
		}
		if(found){
		    printf("Minimum length of subarray to get  %d  is  %d",x,minLen);
		    printf("SubArray is:");
		    for (int i = ansStart; i < ansEnd; i++) {
			    printf("\n%d\n", arrA[i]);
		    }
		}else{
		    printf("No subarray to get + %d " , x);
		}
	}

	int main()  {
		int arrA[] = { 1, 5, 4, 40 };

		minSubArray(arrA, 50);

		return 0;
	}

