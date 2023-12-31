#include<bits/stdc++.h>
using namespace std;

//Recursion
class Solution {
    int recur(int ind,int buy,vector<int>& prices){
        if(ind==prices.size())
            return 0;

        if(buy){
            int take=-prices[ind]+recur(ind+1,0,prices);
            int notTake=0+recur(ind+1,1,prices);
            return max(take,notTake);
        }
        else{
            int take=prices[ind]+recur(ind+1,1,prices);
            int notTake=0+recur(ind+1,0,prices);
            return max(take,notTake);
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        return recur(0,1,prices);
    }
};

//Memoisation
class Solution {
    int recur(int ind,int buy,vector<int>& prices,vector<vector<int>>&dp){
        if(ind==prices.size())
            return 0;

        if(dp[ind][buy]!=-1)
            return dp[ind][buy];
        if(buy){
            int take=-prices[ind]+recur(ind+1,0,prices,dp);
            int notTake=0+recur(ind+1,1,prices,dp);
            return dp[ind][buy]=max(take,notTake);
        }
        else{
            int take=prices[ind]+recur(ind+1,1,prices,dp);
            int notTake=0+recur(ind+1,0,prices,dp);
            return dp[ind][buy]= max(take,notTake);
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return recur(0,1,prices,dp);
    }
};

//Tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        dp[n][0]=dp[n][1]=0;

        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                if(buy){
                    int take=-prices[ind]+dp[ind+1][0];
                    int notTake=0+dp[ind+1][1];
                    dp[ind][buy]=max(take,notTake);
                }
                else{
                    int take=prices[ind]+dp[ind+1][1];
                    int notTake=0+dp[ind+1][0];
                    dp[ind][buy]= max(take,notTake);
                }
            }
        }
        return dp[0][1];
    }
};

//Space optimisaton
