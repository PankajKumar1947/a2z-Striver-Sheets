//1838. Frequency of the Most Frequent Element

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, long k) {
       sort(nums.begin(),nums.end());
       const int n=nums.size();
       int i=0;
       int ans=0;

       for(int j=0;j<n;j++){
           k+=nums[j];

           while(k<(long) nums[j]*(j-i+1)){
               k-=nums[i];
               i++;
           }
           ans=max(ans,j-i+1);
       } 
       return ans;
    }
};

int main(){
    vector<int> nums={1,2,4};
    int k=5;
    Solution S;
    int maxFreq=S.maxFrequency(nums,k);
    cout<<"Frequency of the most frequent element is :"<<maxFreq<<endl;
    return 0;
}