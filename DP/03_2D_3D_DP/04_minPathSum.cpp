//64. Minimum Path Sum
#include<bits/stdc++.h>
using namespace std;

//Memoisation:
int mod=10e+7;
class Solution {
    int minSum(int i,int j, vector<vector<int>> & grid,vector<vector<int>> &dp){
        if(i==0 && j==0)
            return grid[0][0]; 
        if(i<0 || j<0)
            return mod;

        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int up=grid[i][j]+minSum(i-1,j,grid,dp);
        int left=grid[i][j]+minSum(i,j-1,grid,dp);

        return dp[i][j]=min(up,left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        
        return minSum(m-1,n-1,grid,dp);

    }
};
//T.C=O(m*n)
//S.C=O(m*n)+O(m*n)  => one for dp and another of recursion stack.

//Tabulation:
int minPathSum(vector<vector<int>>& grid) {
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n,-1));
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 && j==0)
                dp[i][j]=grid[0][0];
            else{
                int up=INT_MAX;
                int left=INT_MIN;
                if(i>0)
                    up=grid[i][j]+dp[i-1][j];
                if(j>0)
                    left=grid[i][j]+dp[i][j-1];

                dp[i][j]=min(up,left);
            }
        }
    }

    return dp[n-1][m-1];

}
//T.C=O(m*n)
//S.C=O(m*n)

//Space optimisation



int main(){
    
    return 0;
}