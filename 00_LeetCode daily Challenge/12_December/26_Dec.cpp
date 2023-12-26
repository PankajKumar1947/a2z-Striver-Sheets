//1155. Number of Dice Rolls With Target Sum
#include<bits/stdc++.h>
using namespace std;

class Solution {
    const int mod=1e9+7;
    long long recur(int dice,int faces,int target,vector<vector<int>>&dp){
        if(target<0)
            return 0;
        if(target==0 && dice!=0)
            return 0;
        if(dice==0 && target!=0)
            return 0;
        if(target==0 && dice==0)
            return 1;

        if(dp[dice][target]!=-1)
            return dp[dice][target];
        long long ans=0;
        for(int i=1;i<=faces;i++){
            ans+=recur(dice-1,faces,target-i,dp);
        }
        return dp[dice][target]=ans%mod;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return recur(n,k,target,dp);
    }
};