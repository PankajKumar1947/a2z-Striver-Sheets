//Maximum sum of non-adjacent elements/ House Robber-I
#include<bits/stdc++.h>
using namespace std;

//Memoisation.
int memoRob(int ind,vector<int> &nums, vector<int> &dp){
    if(ind==0)
        return dp[ind];
    if(ind<0)
        return 0;
    if(dp[ind]!=-1)
        return dp[ind];

    int pick=nums[ind]+memoRob(ind-2,nums,dp);
    int notPick=memoRob(ind-1,nums,dp);
    return dp[ind]=max(pick,notPick);
}
//T.C=O(n)
//S.C=O(n)+O(n)


//Tabulation
int rob(vector<int>& nums) {
    vector<int> dp(nums.size(),-1);
    for(int i=1;i<nums.size();i++){
        int pick=nums[i];
        if(i>1)
            pick+=dp[i-2];
        int notPick=dp[i-1];
        dp[i]=max(pick,notPick);
    }
    return dp[nums.size()-1];
}

//space optimisaton
int robS(vector<int> & nums){
    int prev=nums[0], prev2=0;
    for(int i=1;i<nums.size();i++){
        int pick=nums[i];
        if(i>1)
            pick+=prev2;
        int notPick=prev;
        int curr=max(pick,notPick);
        prev2=prev;
        prev=curr;
    }
    return prev;
}
//T.C=O(n)
//S.C=O(1)

int main(){
    vector<int> nums={2,1,4,9};
    cout<<rob(nums);
    return 0;
}