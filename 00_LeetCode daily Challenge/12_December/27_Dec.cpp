//1578. Minimum Time to Make Rope Colorful
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.length();
        int ans=0;
        int i=0;
        while(i<n){
            int j=i+1;
            int maxi=neededTime[i];
            int sum=maxi;
            while(colors[i]==colors[j] && j<n){
                maxi=max(maxi,neededTime[j]);
                sum+=neededTime[j];
                j++;
            }
            ans+=sum-maxi;
            i=j;
        }
        return ans;
    }
};