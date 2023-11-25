//1685. Sum of Absolute Differences in a Sorted Array

#include<bits/stdc++.h>
using namespace std;

class Solution {

public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        vector<int> prefixSum(n,0);
        vector<int> suffixSum(n,0);

        //prefix sum 
        prefixSum[0]=0;
        for(int i=0;i<nums.size()-1;i++){
            prefixSum[i+1]=prefixSum[i]+nums[i];
        }
        //suffix sum
        suffixSum[n-1]=0;
        for(int i=n-2;i>=0;i--){
            suffixSum[i]=suffixSum[i+1]+nums[i+1];
        }

        for(int i=0;i<nums.size();i++){
            int temp=nums[i]*i-prefixSum[i]+suffixSum[i]-nums[i]*(n-i-1);
            ans.push_back(temp);
        }
        return ans;
    }
};

int main(){
    vector<int> nums={1,4,6,8,10};
    Solution s;
    vector<int> ans=s.getSumAbsoluteDifferences(nums);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}