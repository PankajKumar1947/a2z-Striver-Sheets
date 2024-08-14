#include<bits/stdc++.h>
using namespace std;

//Recursion
class Solution {
    bool check(int ind,int target,vector<int> nums){
        if(target==0)
            return 0;
        if(ind==0)
            return nums[0]==target;
        
        bool notTake=check(ind-1,target,nums);
        bool take=false;
        if(target>=nums[ind])
            take=check(ind-1,target-nums[ind],nums);

        return take | notTake;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        //if there is a odd total sum then division not possible.
        if(sum%2!=0)
            return false;
        //now check for when total sum is not even.
        int target=sum/2;
        return check(nums.size()-1,target,nums);

    }
};
//T.C=O(2^(n*target))
//S.c=O(n) -> n=nums.size();

//memoisations
class Solution {
    bool check(int ind,int target,vector<int> nums,vector<vector<int>>&dp){
        if(target==0)
            return 0;
        if(ind==0)
            return nums[0]==target;
        
        if(dp[ind][target]!=-1)
            return dp[ind][target];
        bool notTake=check(ind-1,target,nums,dp);
        bool take=false;
        if(target>=nums[ind])
            take=check(ind-1,target-nums[ind],nums,dp);

        return dp[ind][target]=take | notTake;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        //if there is a odd total sum then division not possible.
        if(sum%2!=0)
            return false;
        //now check for when total sum is not even.
        int target=sum/2;
        vector<vector<int>>dp(nums.size(),vector<int>(target+1,-1));
        return check(nums.size()-1,target,nums,dp);

    }
};
//T.C=O(m*target)
//S.C=O(m*target)+auxliary stack space


//Tabulation



//Space optimisation
class Solution {
    bool check(int ind,int k,vector<int> nums){
        vector<bool>prev(k+1,0),curr(k+1,0);
        prev[0]=curr[0]=true;
        if(nums[0]<=k)
            prev[nums[0]]=true;

        for(int ind=1;ind<nums.size();ind++){
            for(int target=1;target<=k;target++){
                bool notTake=prev[target];
                bool take=false;
                if(nums[ind]<=target)
                    take=prev[target-nums[ind]];
                    curr[target]=take | notTake;
            }
            prev=curr;
        }
        return prev[k];
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        //if there is a odd total sum then division not possible.
        if(sum%2!=0)
            return false;
        //now check for when total sum is not even.
        int target=sum/2;
        
        return check(nums.size()-1,target,nums);

    }
};