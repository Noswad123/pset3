#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"
#include "sorts.h"

//Utility Functions
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

//Sorts
void bubblesort(int values[], int n)
{
    bool isSorted = false;
    int lastUnsorted = n-1;

    while(!isSorted)
    {
        isSorted=true;
        for(int i=0; i < lastUnsorted; i++){
                if(values[i] >values[i + 1]){
                    swap(&values[i], &values[i + 1]);
                    i=0;
                    isSorted=false;
                }
        }
        lastUnsorted--;
    }
    return;
}

void mergesort(int arr[], int start, int end)
{
    if (start < end)
    {
        int middle = start + (end - start) / 2;     // Same as (start + end)/2, but avoids overflow for large start and end
        mergesort(arr, start, middle);          // Sort first half
        mergesort(arr, middle + 1, end);        // Sort  second half
        merge(arr, start, middle, end);         //Merges the two halves
    }
}

void merge(int arr[], int start, int middle, int end)
{
    int  leftIndex, rightIndex, mergeIndex;
    int leftSize = middle - start + 1;
    int rightSize =  end - middle;
    int leftHalf[leftSize], rightHalf[rightSize];       // create temp arrays

    /* Copy data to temp arrays leftHalf[] and RightHalf[] */
    for (int i = 0; i < leftSize; i++)
        leftHalf[i] = arr[start + i];
    for (int j = 0; j < rightSize; j++)
        rightHalf[j] = arr[middle + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    leftIndex = 0; // Initial index of first subarray
    rightIndex = 0; // Initial index of second subarray
    mergeIndex = start; // Initial index of merged subarray
    while (leftIndex < leftSize && rightIndex < rightSize)
    {
        if (leftHalf[leftIndex] <= rightHalf[rightIndex])
        {
            arr[mergeIndex] = leftHalf[leftIndex];
            leftIndex++;
        }
        else
        {
            arr[mergeIndex] = rightHalf[rightIndex];
            rightIndex++;
        }
        mergeIndex++;
    }

    // Copy the remaining elements of L[], if there are any
    while (leftIndex < leftSize)
    {
        arr[mergeIndex] = leftHalf[leftIndex];
        leftIndex++;
        mergeIndex++;
    }

    // Copy the remaining elements of R[], if there are any
    while (rightIndex < rightSize)
    {
        arr[mergeIndex] = rightHalf[rightIndex];
        rightIndex++;
        mergeIndex++;
    }
}