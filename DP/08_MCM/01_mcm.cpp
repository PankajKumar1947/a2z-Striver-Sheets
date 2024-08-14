// Matrix Chain Multiplication
#include<bits/stdc++.h>
using namespace std;

//Recursion
class Solution{
private:
    int recur(int i,int j,int* arr){
        //base case
        if(i==j)
            return 0;
        
        //trying out all possible ways.
        int mini=1e9;
        for(int k=i;k<=j-1;k++){
            int steps=arr[i-1]*arr[k]*arr[j]
                +recur(i,k,arr)+recur(k+1,j,arr);
            mini=min(steps,mini);
        }
        return  mini;
    }
public:
    int matrixChainMultiplication(int* arr, int n) {
        return recur(1,n,arr);
    }
};
//T.C=exponential
//S.C=O(n)->recursion stack


//Memoisation
class Solution{
private:
    int recur(int i,int j,int* arr,vector<vector<int>>&dp){
        //base case
        if(i==j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        //trying out all possible ways.
        int mini=1e9;
        for(int k=i;k<=j-1;k++){
            int steps=arr[i-1]*arr[k]*arr[j]
                +recur(i,k,arr,dp)+recur(k+1,j,arr,dp);
            mini=min(steps,mini);
        }
        return dp[i][j]=mini;
    }
public:
    int matrixChainMultiplication(int* arr, int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return recur(1,n,arr,dp);
    }
};
//T.C=O(n*n)*n
//S.C=O(n*n)+O(n)

//tabulation
class Solution{
public:
    int matrixChainMultiplication(int* arr, int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        //base case
        for(int i=1;i<=n;i++){
            dp[i][i]=0;
        }

        for(int i=n;i>=1;i--){
            for(int j=i+1; j<=n;j++){
                //copy paste
                int mini=1e9;
                for(int k=i;k<j;k++){
                    int steps=arr[i-1]*arr[k]*arr[j]
                        +dp[i][k]+dp[k+1][j];
                    mini=min(steps,mini);
                }
                dp[i][j]=mini;
            }
        }

        return dp[1][n];
    }
};
//T.C=O(n*n)*n
//S.C=O(n*n)