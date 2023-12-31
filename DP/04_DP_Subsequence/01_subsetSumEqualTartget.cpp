#include<bits/stdc++.h>
using namespace std;

//Recursion
bool check(int ind,int k, vector<int>&arr){
    if(k==0)
        return true;
    if(ind==0){
        return arr[0]==k;
    }

    //pick and not pick
    bool notPick=check(ind-1,k,arr);
    bool pick=false;
    if(arr[ind]<=k)
        pick=check(ind-1,k-arr[ind],arr);
    return pick| notPick;
    
}
//T.C=O(2^(n*k))
//S.C=O(n)+auxialiary stack space


//Memoisation
bool memoi(int ind,int k, vector<int>&arr,vector<vector<int>>&dp){
    if(k==0)
        return true;
    if(ind==0){
        return arr[0]==k;
    }
    if(dp[ind][k]!=-1)
        return dp[ind][k];

    //pick and not pick
    bool notPick=memoi(ind-1,k,arr,dp);
    bool pick=false;
    if(arr[ind]<=k)
        pick=memoi(ind-1,k-arr[ind],arr,dp);
    return dp[ind][k]=pick| notPick; 
}
//T.C=O(n*target)
//S.C=O(n*target)+auxiliary stack space

//Tabulations
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<bool>>dp(n,vector<bool>(k+1,false));
    for(int i=0;i<n;i++)
        dp[i][0]=true;

    dp[0][arr[0]]=true;

    for(int ind=1;ind<n;ind++){
        for(int target=1;target<=k;target++){
            //pick and not pick
            bool notPick=dp[ind-1][target];
            bool pick=false;
            if(arr[ind]<=target)
                pick=dp[ind-1][target-arr[ind]];
            dp[ind][target]=pick| notPick;
        }
    }
    return dp[n-1][k];
}
//T.C=O(n*k)
//S.C=O(n*k)

//space optimisation
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<bool>prev(k+1,false),curr(k+1,false);
    prev[0]=true;
    curr[0]=true;
    if(arr[0]<=k)
        prev[arr[0]]=true;

    for(int ind=1;ind<n;ind++){
        for(int target=1;target<=k;target++){
            //pick and not pick
            bool notPick=prev[target];
            bool pick=false;
            if(arr[ind]<=target)
                pick=prev[target-arr[ind]];
            curr[target]=pick| notPick;
        }
        prev=curr;
    }
    return prev[k];
}
//T.C=O(n*k)
//S.C=O(k)*2