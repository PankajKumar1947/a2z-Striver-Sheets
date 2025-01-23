#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE : pick one by one element and compare with every further elements
bool isSorted(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
        if (arr[j] < arr[i])
            return false;
        }
    }

    return true;
}
/*
    Time Complexity: O(N^2)
    Space Complexity: O(1)
*/

bool isSorted(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1])
        return false;
    }

    return true;
}
/*
    Time Complexity: O(N)
    Space Complexity: O(1)
*/

int main() {
    int arr[] = {1, 2, 3, 4, 5}, n = 5;
    bool ans = isSorted(arr, n);
    if (ans) cout << "True" << endl;
    else cout << "False" << endl;
    return 0;
}

// 1752. Check if Array Is Sorted and Rotated
//BRUTE FORCE: 
bool check(vector<int>& nums) {
    int i=0;
    while(i<nums.size()-1){
        if(nums[i]>nums[i+1])
            break;
        i++;
    }
    if(i+1==nums.size())
        return true;
    for(int j=i+1;j<nums.size()-1;j++){
        if(nums[j]>nums[j+1])
            return false;
    }

    if(nums[0]>=nums[nums.size()-1]) 
        return true;
    return false;
}
/*
    Time Complexity: 2*O(N)
    Space Complexity: O(1)
*/

bool check(vector<int>& nums) {
    int cnt=0;
    for(int i=0;i<nums.size()-1;i++){
        if(nums[i]>nums[i+1])
            cnt++;
    }
    
    if(cnt>1)
        return false;
    if(cnt==1)
        return nums[0]>=nums[nums.size()-1];
    return true;
}
/*
    Time Complexity: O(N)
    Space Complexity: O(1)
*/