//115. Distinct Subsequences
#include<bits/stdc++.h>
using namespace std;

//Recursion
class Solution {
    int recur(int ind1,int ind2,string s,string t){
        if(ind2<0)
            return 1;
        if(ind1<0)
            return 0;

        if(s[ind1]==t[ind2])
            return recur(ind1-1,ind2-1,s,t)+recur(ind1-1,ind2,s,t);
        return recur(ind1-1,ind2,s,t);
    }
public:
    int numDistinct(string s, string t) {
        int m=s.length();
        int n=t.length();
        return recur(m-1,n-1,s,t);
    }
};

//Memoisation
class Solution {
    int recur(int ind1,int ind2,string s,string t,vector<vector<int>>&dp){
        if(ind2<0)
            return 1;
        if(ind1<0)
            return 0;

        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];
        if(s[ind1]==t[ind2])
            return dp[ind1][ind2]= recur(ind1-1,ind2-1,s,t,dp)+recur(ind1-1,ind2,s,t,dp);
        return dp[ind1][ind2]=recur(ind1-1,ind2,s,t,dp);
    }
public:
    int numDistinct(string s, string t) {
        int m=s.length();
        int n=t.length();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return recur(m-1,n-1,s,t,dp);
    }
};

//tabulation
class Solution {
    int mod=1e9;
public:
    int numDistinct(string s, string t) {
        int m=s.length();
        int n=t.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));

        for(int i=0;i<=m;i++)
            dp[i][0]=1;

        for(int ind1=1;ind1<=m;ind1++){
            for(int ind2=1;ind2<=n;ind2++){
                if(s[ind1-1]==t[ind2-1])
                    dp[ind1][ind2]= dp[ind1-1][ind2-1]%mod+dp[ind1-1][ind2]%mod;
                else
                    dp[ind1][ind2]=dp[ind1-1][ind2];
            }
        }
        return dp[m][n];
    }
};
