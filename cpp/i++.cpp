#include <stdio.h>

int main(int argc, char *argv[])
{
	int b = 3;
	int arr[] = { 6, 7, 8, 9, 10};
	int *ptr = arr;
	*(ptr++)  += 123;
	//printf( "%d, %d\n", *ptr, *(++ptr) );
	printf( "%d, %d, %d\n", *ptr, *(++ptr), *ptr );
	return 0;
}
