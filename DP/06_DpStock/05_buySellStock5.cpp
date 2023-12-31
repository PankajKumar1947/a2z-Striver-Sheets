//309. Best Time to Buy and Sell Stock with Cooldown
#include<bits/stdc++.h>
using namespace std;

//Recursion
class Solution {
    int recur(int ind,int buy,vector<int>& prices){
        if(ind>=prices.size())
            return 0;

        //buy
        if(buy){
            int take=-prices[ind]+recur(ind+1,0,prices);
            int notTake=0+recur(ind+1,1,prices);
            return max(take,notTake);
        }
        //sell
        else{
            int sell=prices[ind]+recur(ind+2,1,prices);
            int notSell=0+recur(ind+1,0,prices);
            return max(sell,notSell);
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        return recur(0,1,prices);
    }
};
//T.C=exponentila
//S.C=O(n)


//Memoisation
class Solution {
    int recur(int ind,int buy,vector<int>& prices,vector<vector<int>>&dp){
        if(ind>=prices.size())
            return 0;

        if(dp[ind][buy]!=-1)
            return dp[ind][buy];
        //buy
        if(buy){
            int take=-prices[ind]+recur(ind+1,0,prices,dp);
            int notTake=0+recur(ind+1,1,prices,dp);
            return dp[ind][buy]=max(take,notTake);
        }
        //sell
        else{
            int sell=prices[ind]+recur(ind+2,1,prices,dp);
            int notSell=0+recur(ind+1,0,prices,dp);
            return dp[ind][buy]=max(sell,notSell);
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return recur(0,1,prices,dp);
    }
};
//T.c=O(N*2)
//S.c=O(N*2)+O(n)

//Tabulation 
//can be done in similar way

//space optimisaton
//can be done in similar way