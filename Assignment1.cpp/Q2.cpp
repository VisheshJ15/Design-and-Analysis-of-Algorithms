#include <iostream>
using namespace std;
void merge(int arr[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = 0;
    int temp[100];
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= high)
        temp[k++] = arr[j++];
    for (i = low, k = 0; i <= high; i++, k++)
        arr[i] = temp[k];
}
void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);       
        mergeSort(arr, mid + 1, high); 
        merge(arr, low, mid, high);     
    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main() {
    int arr1[] = {12,11,13,5,6,7};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {38,27,43,3,9,82,10};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Original array 1: ";
    printArray(arr1, n1);
    mergeSort(arr1, 0, n1 - 1);
    cout << "Sorted array 1:   ";
    printArray(arr1, n1);
    cout << endl;
    cout << "Original array 2: ";
    printArray(arr2, n2);
    mergeSort(arr2, 0, n2 - 1);
    cout << "Sorted array 2:   ";
    printArray(arr2, n2);
    return 0;
}
