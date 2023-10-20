//797.Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, 
//find all possible paths from node 0 to node n - 1 and return them in any order.
#include<bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(int node,vector<vector<int>> &grid, vector<vector<int>> &ans,vector<int> &ds,int target){
        ds.push_back(node);
        for(int i=0;i<grid[node].size();i++){
            dfs(grid[node][i],grid,ans,ds,target);
            
        }
        if(node==target)
            ans.push_back(ds);
        ds.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int m=graph.size()-1;
        vector<vector<int>> ans;
        vector<int> ds;
        dfs(0,graph,ans,ds,m);
        return ans;
    }
};
