//120. Triangle :
//Fixed starting point and variable ending point.
#include<bits/stdc++.h>
using namespace std;

//Memoisation
class Solution {
    int minSum(int i,int j, vector<vector<int>> &triangle,int n,vector<vector<int>>&dp){
        //base case 
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(i==n-1)
            return triangle[i][j];
        
        int down=triangle[i][j]+minSum(i+1,j,triangle,n,dp);
        int rightDown=triangle[i][j]+minSum(i+1,j+1,triangle,n,dp);

        return dp[i][j]=min(down,rightDown);

    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return minSum(0,0,triangle,n,dp);
    }
};
//T.C=O(n*m)
//S.C=O(n*n)+recursion stack


//Tabulation:
int minimumTotal(vector<vector<int>>& triangle) {
    int n=triangle.size();
    vector<vector<int>>dp(n,vector<int>(n,-1));
    for(int j=0;j<n;j++){
        dp[n-1][j]=triangle[n-1][j];
    }

    for(int i=n-2;i>=0;i--){
        for(int j=1;j>=0;j--){
            int d=triangle[i][j]+dp[i+1][j];
            int dg=triangle[i][j]+dp[i+1][j+1];
            dp[i][j]=min(d,dg);
        }
    }
    return dp[0][0];
}
//T.C=O(n*m)+O(n)=O(n*m)
//S.C=O(n*m)
