//1266. Minimum Time Visiting All Points
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans=0;
        for(int i=0;i<points.size()-1;i++){
            int temp=max(abs(points[i][0]-points[i+1][0]),abs(points[i][1]-points[i+1][1]));
            ans+=temp;
        }
        return ans;
    }
};