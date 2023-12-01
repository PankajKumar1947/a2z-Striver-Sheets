//1877. Minimize Maximum Pair Sum in Array

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int i=0;
       int j=nums.size()-1;
       int maxi=INT_MIN;
       while(i<j){
           int sum=nums[i]+nums[j];
           maxi=max(maxi,sum);
           i++;
           j--;
       } 
       return maxi;
    }
};

int main(){
    Solution S;
    vector<int> nums={3,5,4,2,4,6};
    int minPairSm=S.minPairSum(nums);
    cout<<"Minimum pair sum of given array is "<<minPairSm<<endl;
    return 0;
}