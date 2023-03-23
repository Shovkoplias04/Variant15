#include <iostream>

using namespace std;

void Merge(int array[], int const left, int const mid,
           int const right)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;
  
    
    int *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
  
    
    for (int i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
  
    int indexOfSubArrayOne
        = 0, 
        indexOfSubArrayTwo
        = 0; 
    int indexOfMergedArray
        = left; 
  
  
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
  
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
  
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}
  
void MergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return;
  
    int mid = begin + (end - begin) / 2;
    MergeSort(array, begin, mid);
    MergeSort(array, mid + 1, end);
    Merge(array, begin, mid, end);
}
  
void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout <<'\n';
}

int main()
{   //Test1
    cout << "Test1. Given array:\n";
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, arr_size);
    MergeSort(arr, 0, arr_size - 1);
    cout << "Sorted array: \n";
    printArray(arr, arr_size);
    //Test2
    cout << "Test2. Given array:\n";
    int arr2[] = {45,67,228,11,3,-23};
    int arr2_size = sizeof(arr2) / sizeof(arr2[0]);
    printArray(arr2, arr2_size);
    MergeSort(arr2, 0, arr2_size - 1);
    cout << "Sorted array: \n";
    printArray(arr2, arr2_size);
    return 0;
}
