//1688. Count of Matches in Tournament
#include<iostream>
using namespace std;

class Solution {
public:
    int numberOfMatches(int n) {
        if(n==1)
            return 0;
        if(n%2==0)
            return n/2+numberOfMatches(n/2);
        else 
            return n/2+numberOfMatches(n/2+1);
    }
};