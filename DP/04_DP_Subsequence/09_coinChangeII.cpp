#include<bits/stdc++.h>
using namespace std;

//Recursion
class Solution {
    int recur(int ind, int amount,vector<int>&coins){
        if(ind==0){
            if(amount%coins[ind]==0)
                return 1;
            return 0;
        }
        if(amount==0)
            return 1;

        int notPick=0+recur(ind-1,amount,coins);
        int pick=0;
        if(amount>=coins[ind])
            pick=recur(ind,amount-coins[ind],coins);


        return notPick+pick;
    }
public:
    int change(int amount, vector<int>& coins) {
        return recur(coins.size()-1,amount,coins);
    }
};
//T.C>>O(2^(n*amount))
//S.C>>O(n)

//Memoisation
class Solution {
    int recur(int ind, int amount,vector<int>&coins,vector<vector<int>>&dp){
        if(ind==0){
            if(amount%coins[ind]==0)
                return 1;
            return 0;
        }
        if(amount==0)
            return 1;

        if(dp[ind][amount]!=-1)
            return dp[ind][amount];

        int notPick=0+recur(ind-1,amount,coins,dp);
        int pick=0;
        if(amount>=coins[ind])
            pick=recur(ind,amount-coins[ind],coins,dp);


        return dp[ind][amount]=notPick+pick;
    }
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return recur(coins.size()-1,amount,coins,dp);
    }
};
//T.C=O(n*amout);
//S.C=O(n*amoount)+auxiliary stack space


//Tabulation
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        //init
        for(int am=0;am<=amount;am++){
            if(am%coins[0]==0)
                dp[0][am]=1;
            else
                dp[0][am]=0;
        }

        for(int ind=1;ind<coins.size();ind++){
            for(int am=0;am<=amount;am++){
                int notPick=0+dp[ind-1][am];
                int pick=0;
                if(am>=coins[ind])
                    pick=dp[ind][am-coins[ind]];


                dp[ind][am]=notPick+pick;
            }
        }
        return dp[coins.size()-1][amount];
    }
};
//T.C=O(n*amount)
//S.C=O(n*amount)