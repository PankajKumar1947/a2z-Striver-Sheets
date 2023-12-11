//1287. Element Appearing More Than 25% In Sorted Array
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n=arr.size();
        vector<int> hash(arr[n-1]+1,0);
        for(int i=0;i<arr.size();i++){
            hash[arr[i]]++;
        }

        for(int i=0;i<hash.size();i++){
            if(hash[i]*100>25*n)
             return i;
        }

        return -1;
    }
};