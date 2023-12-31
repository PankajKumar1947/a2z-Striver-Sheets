//123. Best Time to Buy and Sell Stock III
#include<bits/stdc++.h>
using namespace std;

//Recursion
class Solution {
    int recur(int ind,int buy, int trans,vector<int>&prices){
        if(ind==prices.size() || trans==0)
            return 0;
        
        //buy
        if(buy){
            int buy=-prices[ind]+recur(ind+1,0,trans,prices);
            int notBuy=0+recur(ind+1,1,trans,prices);
            return max(buy,notBuy);
        }
        //selll
        else{
            int sell=prices[ind]+recur(ind+1,1,trans-1,prices);
            int notSell=0+recur(ind+1,0,trans,prices);
            return max(sell,notSell);
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        return recur(0,1,2,prices);
    }
};
//T.C=exponential
//S.C=O(N)

//memoisation
class Solution {
    int recur(int ind,int buy, int trans,vector<int>&prices, vector<vector<vector<int>>>&dp){
        if(ind==prices.size() || trans==0)
            return 0;
        
        if(dp[ind][buy][trans]!=-1)
            return dp[ind][buy][trans];
        //buy
        if(buy){
            int shouldBuy=-prices[ind]+recur(ind+1,0,trans,prices,dp);
            int notBuy=0+recur(ind+1,1,trans,prices,dp);
            return dp[ind][buy][trans]=max(shouldBuy,notBuy);
        }
        //selll
        else{
            int sell=prices[ind]+recur(ind+1,1,trans-1,prices,dp);
            int notSell=0+recur(ind+1,0,trans,prices,dp);
            return dp[ind][buy][trans]=max(sell,notSell);
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
        return recur(0,1,2,prices,dp);
    }
};
//T.C=O(N*2*3)
//T.C=O(N*2*3)+O(N)

//Tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2,vector<int>(3,0)));
        //Base case has been used in declaration
        for(int ind=prices.size()-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int trans=1;trans<=2;trans++){
                    if(buy){
                        int shouldBuy=-prices[ind]+dp[ind+1][0][trans];
                        int notBuy=0+dp[ind+1][1][trans];
                        dp[ind][buy][trans]=max(shouldBuy,notBuy);
                    }
                    //selll
                    else{
                        int sell=prices[ind]+dp[ind+1][1][trans-1];
                        int notSell=0+dp[ind+1][0][trans];
                        dp[ind][buy][trans]=max(sell,notSell);
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};
//T.C=O(N*2*3)
//S.c=O(N*2*3)

//Space optimisation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>after(2,vector<int>(3,0)),cur(2,vector<int>(3,0));
        //Base case has been used in declaration
        for(int ind=prices.size()-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int trans=1;trans<=2;trans++){
                    if(buy){
                        int shouldBuy=-prices[ind]+after[0][trans];
                        int notBuy=0+after[1][trans];
                        cur[buy][trans]=max(shouldBuy,notBuy);
                    }
                    //selll
                    else{
                        int sell=prices[ind]+after[1][trans-1];
                        int notSell=0+after[0][trans];
                        cur[buy][trans]=max(sell,notSell);
                    }
                }
            }
            after=cur;
        }
        return after[1][2];
    }
};
//T.C=O(N*2*3)
//S.C=O(2*3)*2