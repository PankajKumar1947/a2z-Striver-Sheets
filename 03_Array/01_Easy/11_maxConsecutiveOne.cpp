// 485. Max Consecutive Ones

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                count++;
                maxi=max(maxi,count);
            }
            else
                count=0;
        }
        return maxi;
    }
};

int main() {
    vector < int > nums = { 1, 1, 0, 1, 1, 1 };
    Solution obj;
    int ans = obj.findMaxConsecutiveOnes(nums);
    cout << "The maximum  consecutive 1's are " << ans;
    return 0;
}