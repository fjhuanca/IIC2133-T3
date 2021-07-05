#include "heapsort.h"

#include <stdio.h>


/*Obtenido y adaptado levemente desde GeeksForGeeks*/
void heapify(int** arr, int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l][2] > arr[largest][2])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r][2] > arr[largest][2])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
 
// main function to do heap sort
void heapSort(int** arr, int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(&arr[0], &arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

void swap(int** arr, int** arr2){
    int* temp = *arr;
    *arr = *arr2;
    *arr2 = temp;
}
 
