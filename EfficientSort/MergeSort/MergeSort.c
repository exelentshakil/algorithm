#include<stdio.h>
#include<stdlib.h> // malloc, free, qsort, bsearch

//
//  MergeSort.c
//  MergeSort
//
//  Created by Shakil Ahmed on 1/04/2018.
//  Copyright © 2017 Shakil Empire. All rights reserved.
//

void merging(
             int *L, // Left elements
             int nL, // Left elements size
             int *R, // Right elements
             int nR, // Right elements size
             int *A // The main array where the sorted elements have to be
             ){

                int i,j,k; // initializer for the left right and current array

                i=0;j=0;k=0;

                while(i < nL && j < nR)
                {
                   if(L[i] < R[j])A[k++]=L[i++];
                   else A[k++]=R[j++];
                }

                while(i < nL)A[k++]=L[i++]; // Putting the left divided array's rest elements to the array, If any
                while(j < nR)A[k++]=R[j++]; // Putting the right divided array's rest elements to the array, If any

             }


void merge_sort(
                    int *A, // Array to be sorted
                    int n  // Array size
                ){
                    int i, // initializer for filling the Left and Right Arrays
                        *L, // Left divided array
                        *R, // Right divided array
                        mid; // Middle index for divide the array

                    if( n < 2) return; // Base/Corner case

                    mid=n/2;
                    L=(int*)malloc(sizeof(int) * mid);
                    R=(int*)malloc(sizeof(int) * n-mid);

                    for(i=0; i<mid; i++)L[i]=A[i];
                    for(i=mid; i<n; i++)R[i-mid]=A[i];

                    merge_sort(L, mid);
                    merge_sort(R, n-mid);
                    merging(L,mid,R,n-mid,A);
                }



int main()
{
    int i;
    int A[] = {8,9,7,5,3,4};

    int size=sizeof(A) / sizeof(A[0]);

    // Merge Sort

    merge_sort(A, size);

    for(i=0; i<size; i++)
    {
        printf("%d ", A[i]);
    }



    return 0;
}
