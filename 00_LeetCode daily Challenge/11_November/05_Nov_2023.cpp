//1535. Find the Winner of the array game.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getWinner(vector<int>& arr, int k){
        int currentWinner=arr[0];
        int consecutiveWins=0;

        for(int i=1; i<arr.size();i++){
            if(arr[i] > currentWinner) {
                currentWinner = arr[i];
                consecutiveWins = 1;
            } 
            else
                consecutiveWins++;

            if(consecutiveWins == k)
                return currentWinner;
        }
        return currentWinner;
    }
    
};

int main(){
    vector<int> arr={2,1,3,5,4,6,7};
    int k=2;    
    Solution s;
    cout<<"Winner of the array game is : "<<s.getWinner(arr,k);

    return 0;
}