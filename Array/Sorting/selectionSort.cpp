#include <iostream>

using namespace std;

void selectionSort(int *arr, int n)
{
    for (int i = 0; i < n-1; i++)
    {
        int min_idx = i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        if (min_idx != i) 
        {
            int tmp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = tmp;
        }
    }
}

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
}

int main()
{

    int a[8] = {4, 7, 3, 5, 2, 1, 6, 0};
    
    selectionSort(a, 8);
    printArray(a, 8);

    return 0;
}