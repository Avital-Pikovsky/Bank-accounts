#include <stdio.h>
#include "isort.h"
#define LENGTH 20

int main(){

int arr [LENGTH] = {0};

printf("Enter %d nums: ",LENGTH);
    for(int i=0; i<LENGTH; i++)
    scanf(" %d", (arr+i));

insertion_sort(arr, LENGTH);
printf("The sorted array is: ");
for(int j=0; j<LENGTH-1; j++)
    printf("%d,", *(arr+j));
    printf("%d", *(arr+LENGTH-1));
printf("\n");



}
