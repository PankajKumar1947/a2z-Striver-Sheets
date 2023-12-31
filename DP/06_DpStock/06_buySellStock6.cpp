//714. Best Time to Buy and Sell Stock with Transaction Fee
#include<bits/stdc++.h>
using namespace std;

//Recursion,memoisation, and space optimisation can be done in similar way

//Tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        dp[n][0]=dp[n][1]=0;

        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                if(buy){
                    int take=-prices[ind]+dp[ind+1][0]-fee;
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