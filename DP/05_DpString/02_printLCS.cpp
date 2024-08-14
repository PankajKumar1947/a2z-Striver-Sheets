//print longest common subsequence of two string.
#include<bits/stdc++.h>
using namespace std;

string findLCS(int m, int n,string &text1, string &text2){
	// Write your code here.	
    vector<vector<int>>dp(m+1,vector<int>(n+1,-1));

    //base case
    for(int j=0;j<=n;j++){
        dp[0][j]=0;
    }
    for(int i=0;i<=m;i++){
        dp[i][0]=0;
    }

    for(int ind1=1;ind1<=m;ind1++){
        for(int ind2=1;ind2<=n;ind2++){
            if(text1[ind1-1]==text2[ind2-1])
                dp[ind1][ind2]=1+dp[ind1-1][ind2-1];
            else
                dp[ind1][ind2] = max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
        }
    }
    //now finding required answer
    int index=dp[m][n]-1;
    string ans="";
    for(int i=0;i<=index;i++)
        ans+="#";
    
    int i=m,j=n;
    while(i>0 && j>0){
        if(text1[i-1]==text2[j-1]){
            ans[index]=text1[i-1];
            index--;
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
            i--;
        else
            j--;
    }
    return ans;
}

int main(){
    string text1="ababa";
    string text2="cbbcad";
    int m=text1.length();
    int n=text2.length();
    string ans=findLCS(m,n,text1,text2);
    cout<<ans;
    return 0;
}