//91. Decode Ways

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int recur(int ind,string s,vector<int>&dp){
        //base case
        if(ind<=0)
            return 1;
        if(dp[ind]!=-1)
            return dp[ind];
        int single=0,doub=0;

        //pick one digit if not 0
        if(s[ind]!='0')
            single=recur(ind-1,s,dp);

        //pick in pair
        if(ind - 1 >= 0 && (s[ind - 1] == '1' || (s[ind - 1] == '2' && s[ind] <= '6')))
            doub=recur(ind-2,s,dp);
        return dp[ind]=single+doub;
    }
public:
    int numDecodings(string s) {
        int n=s.length();
        vector<int>dp(n,-1);
        if(n==0 || s[0]=='0')
            return 0;
        
        return recur(n-1,s,dp);
    }
};