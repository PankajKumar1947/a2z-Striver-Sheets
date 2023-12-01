//2849. Determine if a cell is reachable in given time or not.

#include<bits/stdc++.h>
using namespace std;

class Solution {
   
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx == fx && sy == fy){
            return t!= 1;
        }
        int dx = abs(fx - sx), dy = abs(fy - sy);
        return max(dx, dy) <= t;
    }
};