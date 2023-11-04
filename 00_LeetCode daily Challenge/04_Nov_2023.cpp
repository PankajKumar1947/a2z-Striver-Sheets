//1503. Last Moments before all ants fall out of a plank.

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        vector<pair<int,char>> ants;
        //pushing left
        for(auto it: left){
            ants.push_back({it,'L'});
        }
        for(auto it: right){
            ants.push_back({it,'R'});
        }

        //sort this ants vector
        sort(ants.begin(),ants.end());
        int maxTime=0;
        for(auto it: ants){
            int first=it.first;
            char direction=it.second;
            int fallTime=0;
            if(direction=='L')
                fallTime=first;
            else
                fallTime=n-first;
            maxTime=max(maxTime,fallTime);
        }
        return maxTime;
    }
};