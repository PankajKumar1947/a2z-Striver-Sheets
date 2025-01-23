#include<bits/stdc++.h>
using namespace std;

//189. Rotate Array : Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
// BRUT FORCE : 2 POINTERS OR 2 LOOPS
void rotate(vector<int>& nums, int k) {
    int temp;
    int size=nums.size();
    k=k%size;
    while(k--){
        temp=nums[nums.size()-1];
        for(int i=nums.size()-1;i>0;i--){
            nums[i]=nums[i-1];
        }
        nums[0]=temp;
    }
}
/*
    Time Complexity : O(n*k)
    Space Complexity : O(1)
*/


// BETTER APPROACH : STORING THE D ELEMENTS IN temp array
void rotate(vector<int>& nums, int k) {
    vector<int> temp;
    int n=nums.size();
    k=k%n;
    for(int i=n-k;i<n && i>0;i++){
        temp.push_back(nums[i]);
    }

    for(int i=n-k-1;i>=0;i--){
        nums[i+k]=nums[i];
    }

    for(int i=0;i<temp.size();i++){
        nums[i]=temp[i];
    }
}
/*
    Time Complexity: O(n)
    Space Complexity: O(k) since k array element needs to be stored in temp array
*/


// OPTIMAL APPROACH : REVERSAL ALGORITHM
/*
For Rotating Elements to right
    Step 1: Reverse the last k elements of the array
    Step 2: Reverse the first n-k elements of the array.
    Step 3: Reverse the whole array.

    For Eg , arr[]={1,2,3,4,5,6,7} , k=2

For Rotating Elements to left
    Step 1: Reverse the first k elements of the array
    Step 2: Reverse the last n-k elements of the array.
    Step 3: Reverse the whole array.

    For Eg , arr[]={1,2,3,4,5,6,7} , k=2
*/
void reverse(vector<int>& nums, int left, int right){
    while(left<right){
        swap(nums[left],nums[right]);
        left++;
        right--;
    }
}
void rotate(vector<int>& nums, int k) {
    int n=nums.size();
    k=k%n;
    reverse(nums, n-k, n-1);
    reverse(nums, 0, n-k-1);
    reverse(nums, 0, n-1);
}
/*
    Time Complexity - O(N) where N is the number of elements in an array
    Space Complexity - O(1) since no extra space is required
*/


int main(){
    int n = 7;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int k = 2;
    rotate(arr, k);
    cout << "After Rotating the elements to right " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}