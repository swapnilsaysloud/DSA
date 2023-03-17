#include <math.h>
#include <stdio.h>
/* C program to perform all the types of sorts */
/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)

{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}
// A function to print an array of size n
int partition(int arr[], int lo, int hi)
{

    // select the rightmost element as pivot
    int pivot = arr[hi];

    // pointer for greater element
    int i = (lo - 1);

    // traverse each element of the array
    // compare them with the pivot
    for (int j = lo; j < hi; j++)
    {
        if (arr[j] <= pivot)
        {

            // if element smaller than pivot is found
            // swap it with the greater element pointed by i
            i++;

            // swap element at i with element at j
            swap(&arr[i], &arr[j]);
        }
    }

    // swap the pivot element with the greater element at i
    swap(&arr[i + 1], &arr[hi]);

    // return the partition point
    return (i + 1);
}
void quickSort(int array[], int low, int high)
{
    if (low < high)
    {

        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on right of pivot
        int pi = partition(array, low, high);

        // recursive call on the left of pivot
        quickSort(array, low, pi - 1);

        // recursive call on the right of pivot
        quickSort(array, pi + 1, high);
    }
}
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int n, num, i;
    printf("Enter the number of elements in array:\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the array elements: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Input: 1 for Insertion sort \n 2 for Selection sort \n 3 for Bubble Sort \n 4 for Merge Sort \n 5 for Quick Sort.\n ");
    scanf("%d", &num);
    switch (num)
    {
    case 1: // For insertion sort
        insertionSort(arr, n);
        printf("Sorted array: \n");
        printArray(arr, n);
        break;
    case 2: // For selection sort
        selectionSort(arr, n);
        printf("Sorted array: \n");
        printArray(arr, n);
        break;
    case 3: // For bubble sort
        bubbleSort(arr, n);
        printf("Sorted array: \n");
        printArray(arr, n);
        break;
    case 4: // Merge sort
        mergeSort(arr, 0, n - 1);
        printf("\nSorted array is \n");
        printArray(arr, n);
        break;
    case 5: // Quick sort
        quickSort(arr, 0, n - 1);
        printf("Sorted array : \n");
        printArray(arr, n);
        break;
    }
    return 0;
}
