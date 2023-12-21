//661. Image Smoother
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m=img.size();
        int n=img[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                int cnt=0;
                int sum=0;
                for(int k=-1;k<=1;k++){
                    for(int l=-1;l<=1;l++){
                        if(i+k>=0 && j+l>=0 && i+k<m && j+l<n){
                            sum+=img[i+k][j+l];
                            cnt++;
                        }
                    }
                }
                ans[i][j]=sum/cnt;
            }
        }
        return ans;
    }
};