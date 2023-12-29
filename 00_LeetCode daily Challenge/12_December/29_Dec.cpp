//1335. Minimum Difficulty of a Job Schedule
#include<bits/stdc++.h>
using namespace std;

//Recursion-> not submit
class Solution {
    int recur(int ind,int day,vector<int>jobDif){
        //base case
        if(day==1){
            int maxi=jobDif[ind];
            for(int i=ind;i<jobDif.size();i++)
                maxi=max(maxi,jobDif[i]);
            return maxi;
        }

        int maxi=jobDif[ind];
        int finalResult=INT_MAX;
        for(int i=ind;i<=jobDif.size()-day;i++){
            maxi=max(maxi,jobDif[i]);
            int result=maxi+recur(i+1,day-1,jobDif);
            finalResult=min(finalResult,result);
        }
        return finalResult;
    }
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        if(n<d)
            return -1;
        return recur(0,d,jobDifficulty);
    }
};

//memoisation -> memory limit excedded
class Solution {
    int dp[301][11];
    int recur(int ind,int day,vector<int>jobDif){
        //base case
        if(day==1){
            int maxi=jobDif[ind];
            for(int i=ind;i<jobDif.size();i++)
                maxi=max(maxi,jobDif[i]);
            return dp[ind][day]=maxi;
        }

        if(dp[ind][day]!=-1)
            return dp[ind][day];

        int maxi=jobDif[ind];
        int finalResult=INT_MAX;
        for(int i=ind;i<=jobDif.size()-day;i++){
            maxi=max(maxi,jobDif[i]);
            int result=maxi+recur(i+1,day-1,jobDif);
            finalResult=min(finalResult,result);
        }
        return dp[ind][day]=finalResult;
    }
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        if(n<d)
            return -1;
        memset(dp,-1,sizeof(dp));
        return recur(0,d,jobDifficulty);
    }
};

//Tabulation
class Solution {
public:
    int minDifficulty(vector<int>& jobDif, int d) {
        int n=jobDif.size();
        if(n<d)
            return -1;
        int dp[301][11];
        memset(dp,-1,sizeof(dp));
        
        //base case
        for(int i=0;i<n;i++){
            dp[i][1]=*max_element(jobDif.begin()+i,jobDif.end());
        }

        for(int ind=n-1;ind>=0;ind--){
            for(int day=2;day <= min(d,10);day++){
                int maxi=jobDif[ind];
                int finalResult=INT_MAX;
                for(int i=ind;i<=jobDif.size()-day;i++){
                    maxi=max(maxi,jobDif[i]);
                    int result=maxi+dp[i+1][day-1];
                    finalResult=min(finalResult,result);
                }
                dp[ind][day]=finalResult;
            }
        }

        return dp[0][d];
    }
};