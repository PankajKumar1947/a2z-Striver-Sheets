#include<bits/stdc++.h>
using namespace std;

// 547. Number of Provinces

class DisjointSet{  
    public:
        vector<int> rank,parent;
        DisjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            for(int i=0;i<=n;i++){
                parent[i]=i;
            }
        }

        //finding ultimate parent
        int findUPar(int node){
            if(node==parent[node])
                return node;
            return parent[node]=findUPar(parent[node]);
        }

        //find union by rank
        void unionByRank(int u,int v){
            //1. find ultimate parent of u and v
            int ulp_u=findUPar(u);
            int ulp_v=findUPar(v);

            //2. assing the ultimate parent of lower rank to the higher rank
            if(rank[ulp_u]<rank[ulp_v])
                parent[ulp_u]=ulp_v;
            else if(rank[ulp_u]>rank[ulp_v])
                parent[ulp_v]=ulp_u;
            else if(rank[ulp_u]==rank[ulp_v]){
                parent[ulp_v]=ulp_u;
                rank[ulp_u]++;
            }
        }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        DisjointSet ds(n);

        for(int i=0;i<n;i++){
            for(int j=0;j<isConnected[i].size();j++){
                if(isConnected[i][j]==1)
                    ds.unionByRank(i,j);
            }
        }

        int cnt=0;
        //count unique parents
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i)
                cnt++;
        }
        return cnt;
    }
};