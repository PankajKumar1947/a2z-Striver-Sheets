// 136. Single Number

#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE : USING LINEAR SEARCH
int getSingleElement(vector<int> &arr) {
    int n = arr.size();

    //Run a loop for selecting elements:
    for (int i = 0; i < n; i++) {
        int num = arr[i]; // selected element
        int cnt = 0;

        //find the occurrence using linear search:
        for (int j = 0; j < n; j++) {
            if (arr[j] == num)
                cnt++;
        }

        // if the occurrence is 1 return ans:
        if (cnt == 1) return num;
    }
    return -1;
}
/*
    Time Complexity: O(n^2)
    Space Complexity: O(1)
*/

// BETTER APPROACH : USING HASHMAP
int getSingleElement(vector<int> &arr) {
    int n = arr.size();

    // Find the maximum element:
    int maxi = arr[0];
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, arr[i]);
    }

    vector<int> hash(maxi + 1, 0);
    for (int i = 0; i < n; i++) {
        hash[arr[i]]++;
    }

    //Find the single element and return the answer:
    for (int i = 0; i < n; i++) {
        if (hash[arr[i]] == 1)
            return arr[i];
    }

    return -1;
}
/*
    Time Complexity: O(n)
    Space Complexity: O(n)
*/

// BETTER APPROACH : USING MAP
int getSingleElement(vector<int> &arr) {
    int n = arr.size();
    map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        mpp[arr[i]]++;
    }

    //Find the single element and return the answer:
    for (auto it : mpp) {
        if (it.second == 1)
            return it.first;
    }
    return -1;
}
/*
    Time Complexity: O(N) + O(M)
    Space Complexity: O(M)
*/

// OPTIMAL APPROACH : USING XOR
int getSingleElement(vector<int> &arr) {
    int n = arr.size();

    int xorr = 0;
    for(int i = 0; i < n; i++) {
        xorr = xorr ^ arr[i];
    }
    return xorr;
}
/*
    Time Complexity: O(N)
    Space Complexity: O(1)
*/

int main(){
    vector<int> arr = {4, 1, 2, 1, 2};
    int ans = getSingleElement(arr);
    cout << "The single element is: " << ans << endl;
    return 0;
}