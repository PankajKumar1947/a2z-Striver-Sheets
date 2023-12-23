//1496. Path Crossing
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPathCrossing(string path) {
       int x=0,y=0;
       set<vector<int>>st;
       st.insert({0,0});
       for(char it:path){
            if(it=='N')
                y++;
            else if(it=='S')
                y--;
            else if(it=='E')
                x++;
            else
                x--;

            //check if visited or not
            if(st.find({x,y})!=st.end())
                return true;
            st.insert({x,y});
       } 
       return false;
    }
};