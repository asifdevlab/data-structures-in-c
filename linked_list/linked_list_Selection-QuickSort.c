#include <stdio.h>
#include <time.h>

#define MAX 10000

// Selection Sort
void selectionSort(int arr[], int n)
{
    int i, j, min, temp;

    for(i = 0; i < n - 1; i++)
    {
        min = i;
        for(j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[min])
                min = j;
        }

        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

// Quick Sort
void quickSort(int arr[], int low, int high)
{
    int i, j, pivot, temp;

    if(low < high)
    {
        pivot = arr[low];
        i = low + 1;
        j = high;

        while(i <= j)
        {
            while(i <= high && arr[i] <= pivot)
                i++;
            while(arr[j] > pivot)
                j--;

            if(i < j)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        arr[low] = arr[j];
        arr[j] = pivot;

        quickSort(arr, low, j - 1);
        quickSort(arr, j + 1, high);
    }
}

int main()
{
    int n, i;
    int arr1[MAX], arr2[MAX];

    clock_t start, end;
    double time_selection, time_quick;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
        arr2[i] = arr1[i]; // Copy for Quick Sort
    }

    // Selection Sort Timing
    start = clock();
    selectionSort(arr1, n);
    end = clock();
    time_selection = (double)(end - start) / CLOCKS_PER_SEC;

    // Quick Sort Timing
    start = clock();
    quickSort(arr2, 0, n - 1);
    end = clock();
    time_quick = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nTime taken by Selection Sort: %f seconds\n", time_selection);
    printf("Time taken by Quick Sort: %f seconds\n", time_quick);

    if(time_selection > time_quick)
        printf("Quick Sort is faster.\n");
    else if(time_selection < time_quick)
        printf("Selection Sort is faster.\n");
    else
        printf("Both algorithms took equal time.\n");

    return 0;
}
