#include <iostream>

using namespace std;

// Merge two arrays
void merge(int arr[], int first, int mid, int last)
{
    int n1 = mid - first + 1;
    int n2 = last - mid;

    // Copy elements left and right array
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[first+i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid+1+i];

    // Compare between the two arrays and merge them accordingly in the main array
    int i = 0, j = 0, k = first;
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

    // If there is anything left put them in the array
    while (i < n1) 
    {
        arr[k] = L[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        k++;
        j++;
    }

}

// Merge sort
void mergeSort(int arr[], int first, int last)
{
    if (first >= last) return;
    
    int mid = first + (last - first)/2;

    mergeSort(arr, first, mid);
    mergeSort(arr, mid+1, last);
    merge(arr, first, mid, last);
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
    
    mergeSort(a, 0, 7);
    printArray(a, 8);

    return 0;
}