#include<stdio.h>
#include<stdlib.h> // malloc, free, qsort, bsearch

//
//  QuickSort.c
//  QuickSort
//
//  Created by Shakil Ahmed on 12/31/2017.
//  Copyright © 2017 Shakil Empire. All rights reserved.
//

// Swap
void Swap(
              int *_pre,
              int *_next
        ){
              int _accumulator = *_pre;
              *_pre = *_next;
              *_next = _accumulator;
        }

// Partition
int partition(
                  int *A,
                  int _start,
                  int _end
              ){
                  int _pIndex, _pivot, _i;

                  // Pivot
                  _pivot = A[_end];

                  // Partition index
                  _pIndex = _start;

                  for(_i = _start; _i<_end; _i++)
                  {
                     if(A[_i] < _pivot)
                     {
                        Swap(&A[_i], &A[_pIndex]);
                        _pIndex++;
                     }
                  }

                  Swap(&A[_pIndex], &A[_end]);

                  // Return the pIndex
                  return _pIndex;
              }

// Quick Sort

void QuickSort(
                    int *A,
                    int _start,
                    int _end
               ){

                    if(_start < _end)
                    {
                        int _pIndex = partition(A, _start, _end);
                        QuickSort(A, _start, _pIndex-1);
                        QuickSort(A, _pIndex+1, _end);
                    }

               }

int main()
{
    int i;
    int A[] = {8,9,7,5,3,4};

    int size=sizeof(A) / sizeof(A[0]);

    // Quick Sort

    QuickSort(A, 0, size-1);

    for(i=0; i<size; i++)
    {
        printf("%d ", A[i]);
    }


    return 0;
}
