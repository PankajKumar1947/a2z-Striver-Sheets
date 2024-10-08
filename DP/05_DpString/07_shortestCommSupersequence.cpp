//1092. Shortest Common Supersequence
#include<bits/stdc++.h>
using namespace std;

class Solution { 
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m=str1.length();
        int n=str2.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));

        //base case
        for(int j=0;j<=n;j++)
            dp[0][j]=0;
        for(int i=0;i<=m;i++)
            dp[i][0]=0;

        for(int ind1=1;ind1<=m;ind1++){
            for(int ind2=1;ind2<=n;ind2++){
                if(str1[ind1-1]==str2[ind2-1])
                    dp[ind1][ind2]=1+dp[ind1-1][ind2-1];
                else
                    dp[ind1][ind2] = max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
            }
        }
        //now finding required answer
        int index=dp[m][n]-1;
        string ans="";
        
        int i=m,j=n;
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                ans+=str1[i-1];
                index--;
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                ans+=str1[i-1];
                i--;
            }
            else{
                ans+=str2[j-1];
                j--;
            }
        }
        while(i>0){
            ans+=str1[i-1];
            i--;
        }
        while(j>0){
            ans+=str2[j-1];
            j--;
        }
        //required answer is reverse of ans.
        reverse(ans.begin(),ans.end());

        return ans;
    }
};