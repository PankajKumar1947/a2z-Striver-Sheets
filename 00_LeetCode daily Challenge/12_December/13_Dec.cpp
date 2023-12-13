//1582. Special Positions in a Binary Matrix

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        unordered_map<int,int>mp1,mp2;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==1){
                    mp1[i]++;
                    mp2[j]++;
                }
            }
        }
        int cnt=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1){
                    if(mp1[i]==1 && mp2[j]==1)
                        cnt++;
                }
            }
        }

        return cnt;
        
    }
};