#include <iostream>

using namespace std;

// Inserrtion sort
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
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
    
    insertionSort(a, 8);
    printArray(a, 8);

    return 0;
}