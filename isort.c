#include <stdio.h>
#include "isort.h"

void shift_element(int* arr, int i){
    //int *tmp;
    for(int j=i; j>0; j--){
        *(arr+j) = *(arr+(j-1));
    }
    //arr = tmp;

}

void insertion_sort(int* arr, int len){
    for(int i=0; i<len; i++){
        int min, minIndex;
            min = *(arr+i);
        for(int j=i; j<len-1; j++){
            if(min > *(arr+j+1)){
                min = *(arr+j+1);
                minIndex = j+1;
            }
        }
        if(min != *(arr+i)){
            shift_element(arr+i, minIndex-i);
            *(arr+i) = min;
        }
       
    }       
}

