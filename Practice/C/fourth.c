#include<stdio.h>
typedef int A[];
int main() {
	A a = {1,2,3};
	int index = 0;
	for (index=0; index<40; index++)
		printf("%d\n", a[index]);
}
