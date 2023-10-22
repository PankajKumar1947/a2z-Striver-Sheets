//Given a directed acyclic graph, with n vertices numbered from 0 to n-1, and
// an array edges where edges[i] = [fromi, toi] represents a directed edge from node fromi to node toi.
//Find the smallest set of vertices from which all nodes in the graph are reachable.
// It's guaranteed that a unique solution exists.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<int> vis(n,0);
        //marking the visited array which has incoming edges
        for(int i=0;i<edges.size();i++){
            vis[edges[i][1]]=1;
        }
        //pushing those nodes which has been unmarked.
        for(int i=0;i<n;i++){
            if(vis[i]==0)
             ans.push_back(i);
        }
        return ans;
    }
};

//HInts:
//1. A node that does not have any incoming edge can only be reached by itself.
//2. Any other node with incoming edges can be reached from some other node.
//3. We only have to count the number of nodes with zero incoming edges.