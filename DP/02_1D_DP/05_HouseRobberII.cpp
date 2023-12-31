//213. House Robber II

#include<bits/stdc++.h>
using namespace std;

//Approach:
//Make 2 array in First one array nums[0] is absent. and in Second one array nums[end] is absent.
//find the max of answer by applying houseRobberI on both 2 arrays. 
int houseRobberI(vector<int> & nums){
    int prev=nums[0], prev2=0;
    for(int i=1;i<nums.size();i++){
        int pick=nums[i];
        if(i>1)
            pick+=prev2;
        int notPick=prev;
        int curr=max(pick,notPick);
        prev2=prev;
        prev=curr;
    }
    return prev;
}

int HouseRobII(vector<int>& nums) {
    vector<int> temp1;
    vector<int> temp2;
    for(int i=0;i<nums.size();i++){
        if(i!=0)
            temp1.push_back(nums[i]);
        if(i!=nums.size()-1)
            temp2.push_back(nums[i]);
    }
    return max(houseRobberI(temp1),houseRobberI(temp2));
}

int main(){
    vector<int> nums={1,2,3,1};
    cout<<"Ans= "<<HouseRobII(nums);
    return 0;
}