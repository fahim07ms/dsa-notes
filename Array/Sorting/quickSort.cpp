#include <iostream>

using namespace std;

// Find out the pivot's correct index
int partition(int arr[], int low, int high)
{
    // Assump the last elem as pivot
    int pivot = arr[high];

    // Index of smaller element and indicates 
    // the right position of pivot found so far
    int i = low - 1;

    // Traverse arr[low..high] and move all smaller
    // elements on left side. Elements from low to 
    // i are smaller after every iteration
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            int tmp = arr[j];
            arr[j] = arr[i];
            arr[i] = tmp;
        }
    }

    // Bring the pivot to correct posittion
    int tmp = arr[i+1];
    arr[i+1] = pivot;
    arr[high] = tmp;

    return i+1;
}

// Quick sort
void quickSort(int arr[], int low, int high)
{
    if (low >= high) return;

    // Pivot index
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi-1);
    quickSort(arr, pi+1, high);

}

// Prints the elements of the array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
}

int main()
{

    int a[8] = {4, 7, 3, 5, 2, 1, 6, 0};
    
    quickSort(a, 0, 7);
    printArray(a, 8);

    return 0;
}