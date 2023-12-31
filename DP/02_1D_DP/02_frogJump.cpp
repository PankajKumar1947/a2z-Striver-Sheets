// Frog Jump: Find minimum energy consumed to reach n'th starirs
#include <bits/stdc++.h> 
using namespace std;

//recursive solution : TLE and SC error
int recurFrogJump(int ind,vector<int> &a){
    if(ind==0)
        return 0;
    int left=recurFrogJump(ind-1,a)+abs(a[ind]-a[ind-1]);
    int right=INT_MAX;
    if(ind>1)
        right=recurFrogJump(ind-2,a)+abs(a[ind]-a[ind-2]);

    return min(left,right);
}

//memoization
int memoFrogJump(int ind,vector<int> &a, vector<int> &dp){
    if(ind==0)
        return 0;
    if(dp[ind]!=-1)
        return dp[ind];

    int left=recurFrogJump(ind-1,a)+abs(a[ind]-a[ind-1]);
    int right=INT_MAX;
    if(ind>1)
        right=recurFrogJump(ind-2,a)+abs(a[ind]-a[ind-2]);
    
    return dp[ind]=min(left,right);
    
}
//S.C=O(n)+O(n), T.C=O(n)

//tabulation
int tabulFrogJump(int n, vector<int> &height){
    vector<int> dp(n,-1);
    dp[0]=0;

    for(int i=1;i<=n-1;i++){
        int firstStep=dp[i-1]+abs(height[i]-height[i-1]);
        int secondStep=INT_MAX;
        if(i>1)
            secondStep=dp[i-2]+abs(height[i]-height[i-2]);

        dp[i]=min(firstStep,secondStep);
    }
    return dp[n-1];
}

//space optimisation
int spOptFrogJump(int n, vector<int> &heigth){
    int prev2=0;
    int prev=0;
    for(int i=1;i<n;i++){
        int firstStep=prev+abs(heigth[i]-heigth[i-1]);
        int secondStep=INT_MAX;
        if(i>1)
            secondStep=prev2+abs(heigth[i]-heigth[i-2]);
        
        int curr=min(firstStep,secondStep);
        prev2=prev;
        prev=curr;
    }
    return prev;
}


int main(){
    vector<int> height{30,10,60 , 10 , 60 , 50};
    int n=height.size();
    cout<<"Minimum energy consumed to reach "<<n<<" th stairs is "<<spOptFrogJump(n,height);
    return 0;
}