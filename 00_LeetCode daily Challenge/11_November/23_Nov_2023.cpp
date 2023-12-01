// 1630. Arithmetic Subarrays
#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool check(vector<int> &temp){
        if(temp.size()==1)
            return true;
        sort(temp.begin(),temp.end());
        int d=temp[1]-temp[0];
        for(int i=2;i<temp.size();i++){
            if(temp[i]-temp[i-1]!=d)
                return false;
        }
        return true;
    }
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int i=0;i<l.size();i++){
            vector<int> temp;
            //pushing the required elements in temp 
            //temp.insert(temp.end(),nums.begin()+l[i],nums.begin()+r[i]+1);
            for(int j=l[i];j<=r[i];j++)
                temp.push_back(nums[j]);
            if(check(temp))
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans;
    }
};

int main(){
    vector<int> nums={4,6,5,9,3,7};
    vector<int> l={0,0,2};
    vector<int> r={2,3,5};
    Solution s;

    vector<bool> ans=s.checkArithmeticSubarrays(nums,l,r);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}