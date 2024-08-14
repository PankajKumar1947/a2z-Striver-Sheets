#include<bits/stdc++.h>
using namespace std;

//replace 2 with k in question number-3 i.e, previous question.
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>>after(2,vector<int>(k+1,0)),cur(2,vector<int>(k+1,0));
        //Base case has been used in declaration
        for(int ind=prices.size()-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int trans=1;trans<=k;trans++){
                    if(buy){
                        int shouldBuy=-prices[ind]+after[0][trans];
                        int notBuy=0+after[1][trans];
                        cur[buy][trans]=max(shouldBuy,notBuy);
                    }
                    //selll
                    else{
                        int sell=prices[ind]+after[1][trans-1];
                        int notSell=0+after[0][trans];
                        cur[buy][trans]=max(sell,notSell);
                    }
                }
            }
            after=cur;
        }
        return after[1][k];
    }
};
//T.C=O(N*2*K)
//S.C=O(2*k)*2