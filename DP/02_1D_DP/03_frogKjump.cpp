//frog jump with k distance (Q-2 follow up question)
#include<bits/stdc++.h>
using namespace std;

//memoization
int memoKfrogJump(int ind, int k, vector<int> height,vector<int> &dp){
    if(ind==0)
        return 0;
    
    if(dp[ind]!=-1)
        return dp[ind];
    
    int minSteps=INT_MAX;
    for(int i=1;i<=k;i++){
        if(ind-i >=0){
            int jump=memoKfrogJump(ind-i,k,height,dp)+abs(height[ind]-height[ind-i]);
            minSteps=min(minSteps,jump);
        }
    }
    return dp[ind]=minSteps;
}
int solve(int n, vector<int>& height, int k) {
    vector<int> dp(n, -1);
    return memoKfrogJump(n-1,k,height,dp); // Start the recursion from the last index
}
//T.C=O(n) S.C=O(n)+O(n)

//tabulaton
int tabulKfrogJump(int n, vector<int> &height,int k){
    vector<int> dp(n,-1);
    dp[0]=0;
    for(int i=1;i<n;i++){
        int minSteps=INT_MAX;
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                int jump=dp[i-j]+abs(height[i]-height[i-j]);
                minSteps=min(minSteps,jump);
            }
        }
        dp[i]=minSteps;
    }
    return dp[n-1];
}

//Space optimisation: space can't be optimises so effiecently. 
//because in worst case it may same as the space complexity at tabulation format.


int main(){
    vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size();
    int k = 2;
    cout<<"Min energy for k energy jump "<<tabulKfrogJump(n,height,k);
    return 0;
}
