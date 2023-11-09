//1759. Count number of homogeneous substring

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countHomogenous(string s) {
        const int MOD=1000000007;
        long long ans=0;
        int i=0;
        while(i<s.length()){
            int j=i+1;
            int cntChar=1;
            while(s[i]==s[j]){
                j++;
                cntChar++;
            }           
            ans=(ans+(1LL*cntChar * (cntChar + 1) / 2) % MOD) % MOD;
            i=j;
        }
        return static_cast<int>(ans);
    }
};

int main(){
    Solution s;
    string temp="abbcccaa";
    cout<<"The number of homogeneous substring in "<<temp<<" is "<<s.countHomogenous(temp);

    return 0;
}