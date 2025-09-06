	/* generate all permutations for 0 to n store in input
	randomize sort and store in output file
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void swap(int *a , int *b )
{
	int temp  =*a ; 
	*a = *b ; 
	*b = temp ; 
}


int partition(int* arr, int low , int high) 
{
	int ind = low + rand() % (high - low + 1); // note this line
	swap(&arr[ind] , &arr[high]);
	int pivot = arr[high] ; 
	int i = low-1 ; 
	int j = low ; 
	while(j<high)
	{
		if(arr[j] < pivot )
		{
			i++ ; 
			swap(&arr[j] , &arr[i] ) ; 
		}
		j++;
	}
	swap(&arr[i+1] , &arr[high] ) ; 
	return (i+1);
}


void randomizedQsort (int* arr, int low, int high)
{
	if(low<high)
	{
		int pi = partition(arr, low , high); 
		randomizedQsort(arr, low, pi - 1) ; 
		randomizedQsort(arr, pi+1, high); 
	}
}
		

void processPermutation (int* arr , FILE* fptr , int n , FILE* fptr2)
{
	for(int i =0 ; i < n ; i++)
	{
		fprintf(fptr , "%d " , arr[i]);
	}
	fprintf(fptr , "\n");
	int temp[n] ; 
	for(int i = 0  ; i < n ; i++ )
		temp[i] = arr[i] ; 
	randomizedQsort(temp , 0 , n-1 );
	for(int i = 0 ; i < n ;i++)
	{
		fprintf(fptr2 , "%d " , temp[i] ) ; 
	}
	fprintf(fptr2 ,"\n") ; 
}

void generatePermutation (int* arr, int start ,int n , FILE* fptr ,FILE * fptr2)
{	
	if(start == n)
	{
		processPermutation(arr , fptr, n , fptr2) ; 
		return ;
	}
	
	for(int i = start ; i< n ; i++)
	{
		swap(&arr[i],&arr[start]);
		generatePermutation(arr, start+1 , n, fptr  ,fptr2);
		swap(&arr[i],&arr[start]);
	}
	
}

int main ()
{		
	srand(time(NULL));
	int n ;
	printf("Enter value of n  : " );
	scanf("%d", &n); 
	FILE* fptr1 = fopen("input.txt" , "w");
	FILE* fptr2 = fopen("output.txt" ,"w" ); 
	int arr[n] ; 
	for(int i = 0 ; i< n ; i++)
		arr[i] = i ; 
	generatePermutation(arr , 0 , n , fptr1 , fptr2) ; 
	return 0 ;
}