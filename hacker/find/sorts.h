//Utility functions
void swap(int *a, int *b);

//Sorts

void bubblesort(int values[], int n);       //Uses swap();


void mergesort(int arr[], int start, int end);          //Uses merge();
/*
Merges two subarrays of arr[].
    First subarray is arr[l..m]
     Second subarray is arr[m+1..r]
*/
void merge(int arr[], int start, int middle, int end);  //must include with mergesort();