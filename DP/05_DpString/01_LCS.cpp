//find length of longest commmon subsequence of a string.
#include<bits/stdc++.h>
using namespace std;

//Recursion
class Solution {
    int recur(int ind1,int ind2, string text1, string text2){
        if(ind1<0 || ind2<0)
            return 0;

        //if character matched
        if(text1[ind1]==text2[ind2])
            return 1+recur(ind1-1,ind2-1,text1,text2);
        return max(recur(ind1-1,ind2,text1,text2),recur(ind1,ind2-1,text1,text2));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        return recur(m-1,n-1,text1,text2);
    }
};
//T.C=O(2^m * 2^n)
//T.C=O(m*n)

//Memoisation
class Solution {
    int recur(int ind1,int ind2, string text1, string text2,vector<vector<int>>&dp){
        if(ind1==0 || ind2==0)
            return 0;
        
        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];
        //if character matched
        if(text1[ind1-1]==text2[ind2-1])
            return dp[ind1][ind2]=1+recur(ind1-1,ind2-1,text1,text2,dp);
        //character not matched
        return dp[ind1][ind2] = max(recur(ind1-1,ind2,text1,text2,dp),recur(ind1,ind2-1,text1,text2,dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return recur(m,n,text1,text2,dp);
    }
};
//T.C=O(n*m)
//S.C=O(n*m)+O(n+m)

//Tabulation
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));

        //base case
        for(int j=0;j<=n;j++){
            dp[0][j]=0;
        }
        for(int i=0;i<=m;i++){
            dp[i][0]=0;
        }

        for(int ind1=1;ind1<=m;ind1++){
            for(int ind2=1;ind2<=n;ind2++){
                if(text1[ind1-1]==text2[ind2-1])
                    dp[ind1][ind2]=1+dp[ind1-1][ind2-1];
                else
                     dp[ind1][ind2] = max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
            }
        }
        return dp[m][n];
    }
};
//T.c=O(n*m)
//S.C=O(n*m)

//Space optimisation
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        vector<int>prev(n+1,0),cur(n+1,0);

        //base case
        for(int j=0;j<=n;j++){
            prev[j]=0;
        }

        for(int ind1=1;ind1<=m;ind1++){
            for(int ind2=1;ind2<=n;ind2++){
                if(text1[ind1-1]==text2[ind2-1])
                    cur[ind2]=1+prev[ind2-1];
                else
                     cur[ind2] = max(prev[ind2],cur[ind2-1]);
            }
            prev=cur;
        }
        return prev[n];
    }
};
//T.c=O(n*m)
//S.C=O(n)*2
