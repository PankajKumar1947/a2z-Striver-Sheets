// 70. Climbing Stairs
#include<iostream>
#include<vector>
using namespace std;

//memoziation
class Solution {
private:
    //memozitaion
    int dp(int n, vector<int> &dP){
        if(n==1 || n==0)
            return 1;
        if(dP[n]!=-1)
            return dP[n];
        return dP[n]=dp(n-1,dP)+dp(n-2,dP);
    }
    //T.C=O(n)
    //S.C=O(n)+O(n)
public:
    int climbStairs(int n) {
        vector<int> dP(n+1,-1);
        return dp(n,dP);
    }
};

//tabulation
class Solution1 {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
//T.C=O(n)
//S.C=O(n)

//sapce optimisation
class Solution2 {
public:
    int climbStairs(int n) {
        int prev2=1;
        int prev=1;
        for(int i=2;i<=n;i++){
            int curr=prev2+prev;
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};
//T.C=O(n)
//S.C=O(1)


int main(){
    Solution2 s;
    int n=5;
    cout<<"Ways of climbing stairs "<<s.climbStairs(n);
    return 0;
}