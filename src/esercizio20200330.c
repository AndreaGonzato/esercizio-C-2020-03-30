#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


unsigned long fibonacci(unsigned int n);
unsigned long * fibonacci_array(unsigned int n);
void printArray(unsigned long * arrayToBePrint, int arrayLength);
//unsigned long * make_copy_of_array(unsigned long src_array [] , unsigned int array_dimension) {

int main(int argc, char *argv[]) {

	int fibonacci_result_length = 40;
	unsigned long * fibonacci_result = fibonacci_array( fibonacci_result_length - 1 );
	unsigned long * fibonacci_result_copy;
	fibonacci_result_copy = malloc(fibonacci_result_length * sizeof(unsigned long));
	if (fibonacci_result_copy == NULL) {
		perror("malloc eror");
		return EXIT_FAILURE;
	}
	memcpy(fibonacci_result_copy, fibonacci_result, fibonacci_result_length * sizeof(unsigned long));


	printArray(fibonacci_result_copy, fibonacci_result_length);

	return 0;
}


unsigned long fibonacci(unsigned int n)
{
	if( n == 0 || n == 1){
		return (unsigned long)n;
	}else{
		return (unsigned long) (fibonacci(n-1) + fibonacci(n-2));
	}
}

unsigned long * fibonacci_array(unsigned int n){
	unsigned long *arrayResult;
	arrayResult = calloc( n+1, sizeof(unsigned long));

	// check calloc invocation
	if(arrayResult == NULL){
		perror("calloc error!");
		exit(EXIT_FAILURE);
	}

	if( n+1 >= 1){
		arrayResult[0] = 0;
	}
	if( n+1 >= 2){
		arrayResult[1] = 1;
	}
	for(int i = 2 ; i < n+1 ; i++){
		arrayResult[i] = (arrayResult[i-1] + arrayResult[i-2]);
	}
	return arrayResult;
}

void printArray(unsigned long * arrayToBePrint, int arrayLength){
	if(arrayLength >= 1){
		printf("[%lu",arrayToBePrint[0]);
	}
	for (int i = 1 ; i < arrayLength ; i++){
		printf(", %lu",arrayToBePrint[i]);
	}
	if(arrayLength >= 1){
		printf("]\n");
	}
}

/*

unsigned long * make_copy_of_array(unsigned long src_array [] , unsigned int array_dimension)
{
	if (src_array == NULL)
		return NULL;

	unsigned long * result;

	result = malloc(array_dimension * sizeof(unsigned long));
	if (result == NULL) {
		perror("malloc eror");
		return EXIT_FAILURE;
	}

	memcpy(result, src_array, array_dimension * sizeof(unsigned long));


	return result;
}
*/
