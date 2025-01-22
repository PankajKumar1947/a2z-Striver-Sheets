#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>& arr) {
    // code here
    for(int i=1;i<arr.size();i++){
        int j=i;
        int temp=arr[i];
        
        while(j-1>=0 && arr[j-1]>temp){
            arr[j]=arr[j-1];
            j--;
        }
        
        arr[j]=temp;
    }
}

// insertion sort using recursion
void insertion_sort(int arr[], int i, int n) {
    // Base Case: i == n.
    if (i == n) return;

    int j = i;
    while (j > 0 && arr[j - 1] > arr[j]) {
        int temp = arr[j - 1];
        arr[j - 1] = arr[j];
        arr[j] = temp;
        j--;
    }

    insertion_sort(arr, i + 1, n);
}

int main()
{
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before Using insertion Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    insertion_sort(arr, 0, n);
    cout << "After Using insertion sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}