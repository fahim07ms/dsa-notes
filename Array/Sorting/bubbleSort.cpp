#include <iostream>

using namespace std;

// Bubble sort
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        int swapped = 0;
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;

                swapped = 1;
            }
        }
        if (!swapped) break;
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
    
    bubbleSort(a, 8);
    printArray(a, 8);

    return 0;
}