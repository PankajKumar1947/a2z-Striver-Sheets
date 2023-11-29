//191. Number of 1 Bits

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt=0;
        while(n!=0) {
            cnt+= n&1;
            n>>= 1; 
        }
        return cnt;
    }
};

int main(){
    uint32_t n=00000000000000000000000000001011;
    Solution s;
    cout<<"The number of 1 bit in the given number is "<<s.hammingWeight(n);
    return 0;
}