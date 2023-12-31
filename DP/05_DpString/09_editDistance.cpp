//72. Edit Distance
#include<bits/stdc++.h>
using namespace std;

//Recursion
class Solution {
    int recur(int i,int j,string word1,string word2){
        //base case
        if(i<0)
            return j+1;
        if(j<0)
            return i+1;

        if(word1[i]==word2[j])
            return recur(i-1,j-1,word1,word2);

        int insertion=recur(i-1,j-1,word1,word2);
        int deletion=recur(i-1,j,word1,word2);
        int replace=recur(i,j-1,word1,word2);

        return 1+min(insertion,min(deletion,replace));
    }
public:
    int minDistance(string word1, string word2) {
        return recur(word1.size()-1,word2.size()-1,word1,word2);
    }
};

//Memoisation
class Solution {
    int recur(int i,int j,string word1,string word2, vector<vector<int>>&dp){
        //base case
        if(i<0)
            return j+1;
        if(j<0)
            return i+1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(word1[i]==word2[j])
            return dp[i][j]= recur(i-1,j-1,word1,word2,dp);

        int insertion=recur(i-1,j-1,word1,word2,dp);
        int deletion=recur(i-1,j,word1,word2,dp);
        int replace=recur(i,j-1,word1,word2,dp);

        return dp[i][j]= 1+min(insertion,min(deletion,replace));
    }
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size(),vector<int>(word2.size(),-1));
        return recur(word1.size()-1,word2.size()-1,word1,word2,dp);
    }
};

//tabulation
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        //base case
        for(int i = 0; i <= n; i++)
            dp[i][0] = i;
        for(int j = 0; j <= m; j++)
            dp[0][j] = j;


        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if (word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
            }
        }
        return dp[n][m];
    }
};

//space optimisation
