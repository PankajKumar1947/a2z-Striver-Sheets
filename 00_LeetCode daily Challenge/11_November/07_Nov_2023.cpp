//1921. Eliminate maximum number of montsters.

#include<bits/stdc++.h>
using namespace std;


//cheated
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<int> time;
        int N = dist.size();
        for (int i = 0; i < N; ++i) {
            time.push_back((dist[i] + speed[i] - 1) / speed[i]);
        }
        sort(begin(time), end(time));
        for (int i = 1; i < N; ++i) {
            if (time[i] < i + 1) return i;
        }
        return N;
    }
};