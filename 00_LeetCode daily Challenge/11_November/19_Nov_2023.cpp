// 1887. Reduction Operations to Make the Array Elements Equal

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cnt=0;
        int last=nums.size()-1;
        for(int i=last-1;i>=0;i--){
            if(nums[i]!=nums[i+1]){
                cnt+=last-i;
            }
        }
        return cnt;
    }
};

int main(){
    Solution s;
    vector<int> nums={1,1,2,2,3};
    cout<<"Number of required reduction operations "<<s.reductionOperations(nums);
    return 0;
}