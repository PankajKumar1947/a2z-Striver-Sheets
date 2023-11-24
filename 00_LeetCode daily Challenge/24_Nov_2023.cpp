//1561. Maximum Number of Coins You Can Get

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int ans=0;
        int i=0,j=piles.size()-2;
        sort(piles.begin(),piles.end());
        while(i<j){
            ans+=piles[j];
            j-=2;
            i++;
        }
        return ans;
    }
};
int main(){
    vector<int> piles={9,8,7,6,5,1,2,3,4};
    Solution s;
    cout<<"Max. Number of Coins you can get "<<s.maxCoins(piles);
    return 0;
}