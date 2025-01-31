#include <bits/stdc++.h>
using namespace std;

// Left Rotate by One Place 
// BRUTE FORCE SOLUTION : USE AN ARRAY TO STORE THE ELEMENTS LEFT ARR[0]
void solve(int arr[], int n) {
    int temp[n];
    for (int i = 1; i < n; i++) {
        temp[i - 1] = arr[i];
    }
    temp[n - 1] = arr[0];
    for (int i = 0; i < n; i++) {
        cout << temp[i] << " ";
    }
    cout << endl;
}
/*
    Time Complexity: O(n), as we iterate through the array only once.
    Space Complexity: O(n) as we are using another array of size, same as the given array.
*/

//OPIMAL SOLUTION : LEFT SHIFT BY ITERATING BY STORING arr[0] ELEMENT
void LeftRotateOnePlace(int arr[], int n){
    int temp = arr[0]; // storing the first element of array in a variable
    for(int i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    arr[n - 1] = temp; // assigned the value of variable at the last index
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
/*
    Time Complexity: O(n), as we iterate through the array only once.
    Space Complexity: O(1) as no extra space is used
*/

int main(){
    int n = 5;

    int arr[] = {1, 2, 3, 4, 5};
    LeftRotateOnePlace(arr, n);
}
