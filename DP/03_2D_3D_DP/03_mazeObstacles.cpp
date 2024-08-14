//63. Unique Paths II 
#include<bits/stdc++.h>
using namespace std;

//Memoisation
class Solution {
    int memo(int i, int j, vector<vector<int>> & obstacleGrid, vector<vector<int>> &dp){
        if(i>=0 && j>=0 && obstacleGrid[i][j]==1)
            return 0;
        if(i==0 && j==0)
            return 1;
        if(i<0 || j<0 )
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int up=0,left=0;
        if(i>0) up=memo(i-1,j,obstacleGrid,dp);
        if(j>0) left=memo(i,j-1,obstacleGrid,dp);

        return dp[i][j]=up+left;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return memo(m-1,n-1,obstacleGrid,dp);
    }
};
//T.C=O(m*n)
//S.C=O(m*n)+O(m*n) ==> One for dp array and one for recursion stack.


//Tabulation:
int uniquePathsObstacles(vector<vector<int>>& obstacleGrid){
    int m=obstacleGrid.size();
    int n=obstacleGrid[0].size();
    vector<vector<int>>dp(m,vector<int>(n,0));
    dp[0][0]=1;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(obstacleGrid[i][j]==1)
                dp[i][j]=0;
            else if(i==0 && j==0)
                dp[i][j]=1;
            else {
                int up=0;
                int left=0;
                if(i>0)
                    up=dp[i-1][j];
                if(j>0)
                    left=dp[i][j-1];

                dp[i][j]=up+left;

            }
        }
    }
    return dp[m-1][n-1];
}
//T.C=O(m*n)
//S.C =O(m*n)


//Space optimisatoin



int main(){
    vector<vector<int>>ObstacleGrid={{0,0,0},{0,1,0},{0,0,0}};
    Solution s;
    cout<<"Number of possible unique paths = "<<uniquePathsObstacles(ObstacleGrid);
    return 0;
}