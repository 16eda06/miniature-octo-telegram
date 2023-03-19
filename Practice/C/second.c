#include<stdio.h>
#include<math.h>
int main() {
	int start=0, step=100;
	while(start<10000){
		printf("sqrt of %5d is %3.3f\n", start, sqrt(start));
		start += step;
	}
}
