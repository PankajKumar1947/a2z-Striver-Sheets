//1424. Diagonal Traverse II

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int rows=nums.size();
        int col=0;
        for(auto it:nums){
            col=max(col,static_cast<int>(it.size()));
        }
        vector<vector<int>> vect(rows+col);
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                vect[i+j].push_back(nums[i][j]);
            }
        }

        vector<int> ans;
        for(int i=0;i<vect.size();i++){
            reverse(vect[i].begin(),vect[i].end());       
            ans.insert(ans.end(),vect[i].begin(),vect[i].end());
        }

        return ans;
    }
};

int main(){
    vector<vector<int>> mat={{1,2,3},{4,5,6},{7,8,9}};
    vector<int> ans;
    Solution s;
    ans=s.findDiagonalOrder(mat);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}