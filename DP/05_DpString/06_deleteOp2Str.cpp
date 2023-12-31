//583. Delete Operation for Two Strings

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        vector<int>prev(n+1,0),cur(n+1,0);

        //base case
        for(int j=0;j<=n;j++){
            prev[j]=0;
        }

        for(int ind1=1;ind1<=m;ind1++){
            for(int ind2=1;ind2<=n;ind2++){
                if(word1[ind1-1]==word2[ind2-1])
                    cur[ind2]=1+prev[ind2-1];
                else
                     cur[ind2] = max(prev[ind2],cur[ind2-1]);
            }
            prev=cur;
        }
        int ans=m+n-2*prev[n];
        return ans;
    }
};