//931. Minimum Falling Path Sum
//Variable starting point and variable ending point.
//Similar code can be used to find maximum falling path sum.

#include<bits/stdc++.h>
using namespace std;


//Memoisation
int mod=1e9;
class Solution {
    int minSum(int i, int j, vector<vector<int>>& matrix, int n, vector<vector<int>> &dp){
        if(j<0 || j>=n)
            return mod ;

        if(i==0)
            return matrix[i][j];
        
        if(dp[i][j]!=-1)
            return dp[i][j];

        int upLeft=matrix[i][j]+minSum(i-1,j-1,matrix,n,dp);
        int up=matrix[i][j]+minSum(i-1,j,matrix,n,dp);
        int upRight=matrix[i][j]+minSum(i-1,j+1,matrix,n,dp);

        return dp[i][j]=min(upLeft,min(up,upRight));

    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>dp(matrix.size(),vector<int>(n,-1));
        
        int ans=INT_MAX;
        for(int j=n-1;j>=0;j--){
            int temp=minSum(m-1,j,matrix,n,dp);
            ans=min(ans,temp);
        }

        return ans;
    }
};

//T.C=O(m*n)*O(n) => time limit excedded for larger input
//S.C=O(m*n)+O(m*n) => one for recursion stack and another for dp array.


//Tabulation
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>dp(matrix.size(),vector<int>(n,-1));
        
        for(int j=0;j<n;j++){
            dp[0][j]=matrix[0][j];
        }

        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                int up=matrix[i][j]+dp[i-1][j];
                int leftUp=1e9;
                int rightUp=1e9;
                if(j-1>=0)
                    leftUp=matrix[i][j]+dp[i-1][j-1];
                if(j+1<n)
                    rightUp=matrix[i][j]+dp[i-1][j+1];
                dp[i][j]=min(up,min(leftUp,rightUp));
            }
        }

        //finding mini
        int mini=dp[n-1][0];
        for(int j=1;j<n;j++){
            mini=min(dp[n-1][j],mini);
        }
        return mini;
    }
};
//T.C=O(n*m)+O(n)
//S.C=O(n*m)

//Space optimisation.
