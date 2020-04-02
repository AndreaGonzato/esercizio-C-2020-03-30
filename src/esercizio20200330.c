#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define	false	0
#define	true	1

unsigned long fibonacci(unsigned int n);
unsigned long * fibonacci_array(unsigned int n);
void printArray(unsigned long * arrayToBePrint, int arrayLength);
unsigned long * make_copy_of_array(unsigned long * src_array , unsigned int array_dimension);
void swap(unsigned long *x, unsigned long *y) ;
void reverse_array(unsigned long * src_array, unsigned int array_dimension);
void bubbleSort(unsigned long * src_array, unsigned int array_dimension);
short int have_same_elements(unsigned long * array1, unsigned int array1_dimension, unsigned long * array2, unsigned int array2_dimension);


int main(int argc, char *argv[]) {

	int fibonacci_result_length = 40;
	unsigned long * fibonacci_result = fibonacci_array( fibonacci_result_length - 1 );

	unsigned long * fibonacci_result_copy = make_copy_of_array(fibonacci_result, fibonacci_result_length);
	int fibonacci_result_copy_length = fibonacci_result_length;
	printf("This is fibonacci_result_copy\n");
	printArray(fibonacci_result_copy, fibonacci_result_length);

	reverse_array(fibonacci_result_copy, fibonacci_result_length);
	printf("This is fibonacci_result_copy after a reverse\n");
	printArray(fibonacci_result_copy, fibonacci_result_length);


	bubbleSort(fibonacci_result_copy, fibonacci_result_length);
	printf("This is fibonacci_result_copy after a bubbleSort\n");
	printArray(fibonacci_result_copy, fibonacci_result_length);

	if(have_same_elements(fibonacci_result, fibonacci_result_length, fibonacci_result_copy, fibonacci_result_copy_length)){
		printf("fibonacci_result and fibonacci_result_copy are now equal\n");
	}else{
		printf("fibonacci_result and fibonacci_result_copy are different\n");
	}

	return 0;
}


unsigned long fibonacci(unsigned int n)
{
	/* fibonacci(93) = 1.2*10^19
	 * fibonacci(94) = 1.9*10^19
	 * But unsigned long range is: [0, 1.84*10^19] so this means an overflow when occur fibonacci(94)
	 * Obviously since the program is not optimized, I do not recommend using fibonacci greater than 50
	 */
	if ( n <= 93){
		if( n == 0 || n == 1){
			return (unsigned long)n;
		}else{
			return (unsigned long) (fibonacci(n-1) + fibonacci(n-2));
		}
	}
	perror("fibonacci is call with a too big parameter ");
	exit(EXIT_FAILURE);
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
		printf("]\n\n");
	}
}


unsigned long * make_copy_of_array(unsigned long src_array [] , unsigned int array_dimension)
{
	if (src_array == NULL){
		return NULL;
	}
	unsigned long * result;
	result = malloc(array_dimension * sizeof(unsigned long));
	// check malloc invocation
	if (result == NULL) {
		perror("malloc eror");
		return EXIT_FAILURE;
	}
	memcpy(result, src_array, array_dimension * sizeof(unsigned long));

	return result;
}


// function to swap two unsigned long
void swap(unsigned long *x, unsigned long *y) {
	unsigned long t = *x;
	*x = *y; // x now point to address of var y
	*y = t;
}


void reverse_array(unsigned long * src_array, unsigned int array_dimension){
	int i = 0;
	int j = array_dimension-1;
	while(i < j){
		swap(&src_array[i], &src_array[j]);
		i++;
		j--;
	}
}


void bubbleSort(unsigned long * src_array, unsigned int array_dimension)
{
	int upperLimit = array_dimension;
	while(upperLimit > 1)
	{
		for(int i=1 ; i<upperLimit ; i++){
		   if(src_array[i-1] > src_array[i]){
			   swap(&src_array[i-1], &src_array[i]);
		   }
		}
		upperLimit--;
	}
}


short int have_same_elements(unsigned long * array1, unsigned int array1_dimension, unsigned long * array2, unsigned int array2_dimension){
	if(array1_dimension != array2_dimension){
		return false;
	}
	for ( int i = 0 ; i < array1_dimension ; i++ ){
		if(array1[i] != array2[i]){
			return false;
		}
	}
	return true;
}
