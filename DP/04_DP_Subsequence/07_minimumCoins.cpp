#include<bits/stdc++.h>
using namespace std;

//recursive solution
class Solution {
    int recur(int ind,int amount,vector<int>&coins){
        if(ind==0){
            if(amount%coins[0]==0)
                return amount/coins[0];
            else
                return 1e9;
        }

        //not pick
        int notPick=recur(ind-1,amount,coins);
        //pick
        int pick=1e9;
        if(amount>=coins[ind])
            pick=1+recur(ind,amount-coins[ind],coins);

        return min(notPick,pick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int ans= recur(coins.size()-1,amount,coins);
        if(ans==1e9)
            return -1;
        else
            return ans;
    }
};
//T.C>>O(2^(n*m)) => exponential 
//S.C>>O(n*m) => stack space

//memoisation
class Solution {
    int memoi(int ind,int amount,vector<int>&coins,vector<vector<int>>&dp){
        if(ind==0){
            if(amount%coins[0]==0)
                return amount/coins[0];
            else
                return 1e9;
        }

        if(dp[ind][amount]!=-1)
            return dp[ind][amount];
        //not pick
        int notPick=memoi(ind-1,amount,coins,dp);
        //pick
        int pick=1e9;
        if(amount>=coins[ind])
            pick=1+memoi(ind,amount-coins[ind],coins,dp);

        return dp[ind][amount]=min(notPick,pick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int ans= memoi(coins.size()-1,amount,coins,dp);
        return ans==1e9 ? -1: ans;
    }
};
//T.C=O(n*amont)
//S.C=O(n*amount)+auxiliary stack space

// Tabulations
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        //initialisation
        for(int am=0;am<=amount;am++){
            if(am%coins[0]==0)
                dp[0][am]=am/coins[0];
            else
                dp[0][am]=1e9;
        }

        for(int ind=1;ind<coins.size();ind++){
            for(int am=0;am<=amount;am++){
                //not pick
                int notPick=dp[ind-1][am];
                //pick
                int pick=1e9;
                if(am>=coins[ind])
                    pick=1+dp[ind][am-coins[ind]];

                dp[ind][am]=min(notPick,pick);
            }
        }

        int ans=dp[coins.size()-1][amount];
        return ans>=1e9 ? -1: ans;
    }
};
//T.C=O(n*amount)
//S.C=O(n*amount)=> dp array

//Space optimisation
