#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    public:
        vector<int> rank,parent;
        DisjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            for(int i=0;i<=n;i++)
                parent[i]=i;
        } 
        //find ultimate parent
        int findUPar(int node){
            if(node==parent[node])
                return node;
            return parent[node]=findUPar(parent[node]);
        }   

        //find union by rank
        void unionByRank(int u,int v){
            int ulp_u=findUPar(u);
            int ulp_v=findUPar(v);

            if(ulp_u==ulp_v)
                return ;

            if(rank[ulp_u]<rank[ulp_v])
                parent[ulp_u]=ulp_v;
            else if(rank[ulp_u]>rank[ulp_v])
                parent[ulp_v]=ulp_u;
            else{
                parent[ulp_v]=ulp_u;
                rank[ulp_u]++;
            }
        }    
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int edgesUsed=0;
        DisjointSet ds(n);

        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            if(ds.findUPar(u)!=ds.findUPar(v)){
                edgesUsed++;
                ds.unionByRank(u,v);
            }
        }
        //find the number of leaders
        int leader=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i)
                leader++;
        }

        int neededEdges=leader-1;
        int remEdges=connections.size()-edgesUsed;

        if(remEdges>=neededEdges)
            return neededEdges;
        else
            return -1;

    }
};