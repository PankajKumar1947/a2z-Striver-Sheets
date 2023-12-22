//1422. Maximum Score After Splitting a String
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int cntOne=count(s.begin(),s.end(),'1');
        int cntZero=0;
        int ans=INT_MIN;
        for(int i=0;i<s.length()-1;i++){
            if(s[i]=='0')
                cntZero++;
            else
                cntOne--;
            ans=max(ans,cntZero+cntOne);
        }
        return ans;
    }
};