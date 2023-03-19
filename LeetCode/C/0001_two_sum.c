#include<stdio.h>

void twoSum(int* nums, int numsSize, int target, int* returnSize){
	int i = 0;
	while (i<numsSize) {
		printf("%d\n", nums[i]);
		i++;
	}
}

int main() {
	int a[4]={1,2,3,4};
	int s;
	twoSum(a, 4, 0, &s); 
}
