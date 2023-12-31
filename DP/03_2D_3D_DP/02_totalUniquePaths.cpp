//62. Unique Paths
#include<bits/stdc++.h>
using namespace std;

//Memoisation
int uniquePathMemo(int i, int j,vector<vector<int>>&dp){
    if(i==0 && j==0)
        return 1;

    if(i<0 || j<0)
        return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];

    int up=uniquePathMemo(i-1,j,dp);
    int left=uniquePathMemo(i,j-1,dp);
    return dp[i][j]=up+left;
}
//T.C=O(m*n)
//S.C=O(m*n)+O(n-1)+O(m-1)



//Tabulation
int uniquePaths(int m, int n) {
vector<vector<int>> dp(m,vector<int>(n,-1));
    dp[0][0]=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 && j==0)
                dp[i][j]=1;
            else{
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
//S.C=O(m*n)


//Space Optimisation
int findUniquePaths(int m,int n){
    vector<int>prev(n,0);
    for(int i=0;i<m;i++){
        vector<int> curr(n,0);
        for(int j=0;j<n;j++){
            if(i==0 && j==0)
                curr[j]=1;
            else{
                int up=0;
                int left=0;
                if(i>0)
                    up=prev[j];
                if(j>0)
                    left=curr[j-1];

                curr[j]=up+left;
            }
        }
        prev=curr;
    }
    return prev[n-1];
}
//T.C=O(m*n)
//S.C=O(n)


int main(){
    int m=3,n=7;
    cout<<"Total number of unique paths is "<<findUniquePaths(m,n);
    return 0;
}