#include<iostream>
#include<vector>
using namespace std;

//Q1. Fibonacci series
//recursion
int fibRecur(int n){
    if(n==0 || n==1)
        return n;
    return fibRecur(n-1)+fibRecur(n-2);
}

//recursion => memoziation
int fibMemo(int n,vector<int> &dp){
    if(n==0 || n==1)
        return n;
    if(dp[n]!=-1)
        return dp[n];
    return dp[n]=fibMemo(n-1,dp)+fibMemo(n-2,dp);
}
//T.C=O(n), S.C=O(n)+O(n) : one for dp vector and another for recursion stack.

//recursion => tabulation
int fibTab(int n){
    vector<int> dp(n+1,-1);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
//T.C=O(n), S.C=O(n); : space for dp array

//space optimization
int fibOptSpace(int n){
    int prev2=0;
    int prev=1;// it will be the answer
    for(int i=2;i<=n;i++){
        int curr=prev+prev2;
        prev2=prev;
        prev=curr;
    }
    return prev;
}
//T.C=O(n), S.C=O(1)

int main(){
    int n=2;
    cout<<n<<" th  fibonacci number in the series is "<<fibRecur(n)<<endl;

    // memoziation
    vector<int> dp(n+1,-1);
    cout<<n<<" th fibonacii number using memoziation is "<< fibMemo(n,dp)<<endl;
    for(int i=0;i<dp.size();i++){
        cout<<dp[i]<<" ";
    }

    cout<<endl;
    //tabulation
    cout<<n<<" th fibonacci number usign tabulation is "<< fibTab(n)<<endl;

    //space optimization
    cout<<n<<" th fibonacci number using space optimization is "<<fibOptSpace(n);


    return 0;
}