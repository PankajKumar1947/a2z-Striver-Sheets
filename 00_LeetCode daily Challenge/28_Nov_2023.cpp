//2147. Number of Ways to Divide a Long Corridor

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfWays(string corridor) {
        int cntSeat=0;
        for(int i=0;i<corridor.length();i++){
            if(corridor[i]=='S')
                cntSeat++;
        }
        //checking if number of seat=0 or not divisible by 2 then ans would be 0
        if(cntSeat==0 || cntSeat%2!=0)
            return 0;

        int seat=0;
        long long ans=1;

        for(int i=0;i<corridor.size();i++){
            if(corridor[i]=='S')
                seat++;

            if(seat==2){
                int cnt=1;
                i++;
                while(i<corridor.size() && corridor[i]=='P'){
                    cnt++;
                    i++;
                }

                if(i==corridor.size()) break;

                ans=(ans*cnt)%1000000007;
                seat=0;
                i--;
            }
        }

        return ans;
    }
};