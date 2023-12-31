//516. Longest Palindromic Subsequence
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string text2=s;
        int m=s.size();
        reverse(text2.begin(),text2.end());
        vector<vector<int>>dp(m+1,vector<int>(m+1,-1));

        //base case
        for(int j=0;j<=m;j++){
            dp[0][j]=0;
        }
        for(int i=0;i<=m;i++){
            dp[i][0]=0;
        }

        for(int ind1=1;ind1<=m;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                if(s[ind1-1]==text2[ind2-1])
                    dp[ind1][ind2]=1+dp[ind1-1][ind2-1];
                else
                     dp[ind1][ind2] = max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
            }
        }
        return dp[m][m];
    }
};