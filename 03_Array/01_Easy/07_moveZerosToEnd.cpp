#include <bits/stdc++.h>
using namespace std;

// 283. Move Zeroes
// BRUTE FORCE : USING ARRAY OF NON-ZERO ELEMENTS AND THEN COPYING
vector<int> moveZeros(int n, vector<int> a) {
    vector<int> temp;
    //copy non-zero elements
    //from original -> temp array:
    for (int i = 0; i < n; i++) {
        if (a[i] != 0)
            temp.push_back(a[i]);
    }

    // number of non-zero elements.
    int nz = temp.size();

    //copy elements from temp
    //fill first nz fields of
    //original array:
    for (int i = 0; i < nz; i++) {
        a[i] = temp[i];
    }

    //fill rest of the cells with 0:
    for (int i = nz; i < n; i++) {
        a[i] = 0;
    }
    return a;
}
/*
    Time Complexity: O(N) + O(X) + O(N-X) ~ O(2*N), where N = total no. of elements,
    X = no. of non-zero elements, and N-X = total no. of zeros.
    Reason: O(N) for copying non-zero elements from the original to the temporary array. O(X) for again copying it back from the temporary to the original array. O(N-X) for filling zeros in the original array. So, the total time complexity will be O(2*N).

    Space Complexity: O(N), as we are using a temporary array to solve this problem and the maximum size of the array can be N in the worst case.
    Reason: The temporary array stores the non-zero elements. In the worst case, all the given array elements will be non-zero.
*/

// BETTER SOLUTION : first count number of zeroes and delete the zeroes from the array and then insert 0 count times in the array.
void moveZeroes(vector<int>& nums) {
    int count=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==0)
        {
            count++;
            nums.erase(nums.begin()+i);
            if(nums[i]==0)
            i--;
        }
    }
    while(count--){
        nums.insert(nums.begin()+nums.size(),0);
    }
}
/*
    Time Complexity : O(N)
    Space Complexity : O(1)
*/

// OPTIMAL SOLUTION : USING 2 POINTER
vector<int> moveZeros(int n, vector<int> a) {
    int j = -1;
    //place the pointer j:
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            j = i;
            break;
        }
    }

    //no non-zero elements:
    if (j == -1) return a;

    //Move the pointers i and j
    //and swap accordingly:
    for (int i = j + 1; i < n; i++) {
        if (a[i] != 0) {
            swap(a[i], a[j]);
            j++;
        }
    }
    return a;
}

/*
    Time Complexity: O(N), N = size of the array.
    Reason: We have used 2 loops and using those loops, we are basically traversing the array once.

    Space Complexity: O(1) as we are not using any extra space to solve this problem.
*/

int main(){
    vector<int> arr = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
    int n = 10;
    vector<int> ans = moveZeros(n, arr);
    for (auto &it : ans) {
        cout << it << " ";
    }
    cout << '\n';
    return 0;
}