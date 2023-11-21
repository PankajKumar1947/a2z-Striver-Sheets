//1814. Count Nice Pairs in an Array

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int rev(int num){
        int revNum=0;
        while(num){
            revNum=revNum*10+num%10;
            num/=10;
        }
        return revNum;
    }
public:
    int countNicePairs(vector<int>& nums) {
        int ans=0;
        unordered_map<int,int> mp;
        const int mod=1e9+7;
        for(auto it:nums){
            int diff=it-rev(it);
            ans=(ans+mp[diff])%mod;
            mp[diff]++;
        }
        return ans;
    }
};