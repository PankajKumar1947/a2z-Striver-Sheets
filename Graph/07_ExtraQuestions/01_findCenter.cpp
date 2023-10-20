//1791. Find the center of the graph:

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int a=edges[0][0];
        int b=edges[0][1];
        int c=edges[1][0];
        int d=edges[1][1];

        int ans=-1;
        if(a==c) ans=a;
        else if(a==d) ans=d;
        else if(b==c) ans=b;
        else if(b==d) ans=d;

        return ans;
    }
};

int main(){
    
}