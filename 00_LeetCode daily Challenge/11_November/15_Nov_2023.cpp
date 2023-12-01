//1846. Maximum Element After Decreasing and Rearranging

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int maxi=1;
        for(int i=0;i<arr.size()-1;i++){
            arr[0]=1;
            if(abs(arr[i]-arr[i+1])>1)
                arr[i+1]=arr[i]+1;
            maxi=max(maxi,arr[i+1]);
        }

        return maxi;
    }
};

int main(){
    Solution S;
    vector<int> arr={2,2,1,2,1};
    int ans=S.maximumElementAfterDecrementingAndRearranging(arr);
    cout<<"Maximum Element after decreasing and rearranging is "<< ans<<endl;
    return 0;
}

//Hint
//1. Sort the array
//2. Decrement each element to the largest integer that satisfies the conditions.