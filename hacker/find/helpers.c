/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"
#include "sorts.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    for(int i=0; i < n; i++){
         if(values[i]==value){
             return true;
         }
    }
    return false;
}

void sort(int values[], int n)
{
    mergesort(values,values[0], values[n-1]);
    return;
}


