#include<bits/stdc++.h>
using namespace std;

// 26. Remove Duplicates from Sorted Array

// BRUTE FORCE : Using set data structure
int removeDuplicates(int arr[], int n) {
    set < int > set;
    for (int i = 0; i < n; i++) {
        set.insert(arr[i]);
    }

    int k = set.size();
    int j = 0;
    for (int x: set) {
        arr[j++] = x;
    }
    return k;
}
/*
    Time complexity: O(n*log(n))+O(n)
    Space Complexity: O(n) 
*/

// OPTIMAL APPROACH : 
int removeDuplicates(vector<int>& nums) {
    int ind=0;
    for(int i=1;i<nums.size();i++){
        if(nums[i]!=nums[ind]){
            ind++;
            nums[ind]=nums[i];
        }
    }
    return ind+1;
}
/*
    Time Complexity : O(N)
    Space Complexity : O(1)
*/

int main() {
    int arr[] = {1,1,2,2,2,3,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = removeDuplicates(arr, n);
    cout << "The array after removing duplicate elements is " << endl;
    for (int i = 0; i < k; i++) {
        cout << arr[i] << " ";
    }
}