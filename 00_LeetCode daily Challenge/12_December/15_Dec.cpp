//1436. Destination City
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int>mpp;
        string ans="";
        for(int i=0;i<paths.size();i++){
            mpp[paths[i][0]]++;
            mpp[paths[i][1]]++;
        }

        for(int i=0;i<paths.size();i++){
            if(mpp[paths[i][1]]==1)
                ans=paths[i][1];
        }
        return ans;
    }
};