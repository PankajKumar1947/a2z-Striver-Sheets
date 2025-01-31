#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE -> USING SORTING
int sortArr(vector<int> &arr){
    sort(arr.begin(), arr.end());
    return arr[arr.size() - 1];
}
// Time Complexity: O(N*log(N))
// Space Complexity: O(n)


// BETTER APPROACH -> USING MAX VARIABLE
int findLargestElement(int arr[], int n){
    int max = arr[0];
    for (int i = 0; i < n; i++){
        if (max < arr[i])
            max = arr[i];
    }
    return max;
}
// Time Complexity: O(N)
// Space Complexity: O(1)

int main(){
    vector<int> arr1 = {2, 5, 1, 3, 0};
    vector<int> arr2 = {8, 10, 5, 7, 9};

    cout << "The Largest element in the array is: " << sortArr(arr1) << endl;
    cout << "The Largest element in the array is: " << sortArr(arr2);

    return 0;
}
