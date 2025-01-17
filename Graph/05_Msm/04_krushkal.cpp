#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank,parent;
    public:
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

class Solution{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]){
        // code here
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                int adjNode=it[0];
                int wt=it[1];
                int node=i;
                edges.push_back({wt,{node,adjNode}});
            }
        }
        
        //connect only those 2 nodes whose ultimate parents are different.
        sort(edges.begin(),edges.end());
        
        int mstwt=0;
        DisjointSet ds(V);
        
        for(auto it:edges){
            int wt=it.first;
            int u=it.second.first;
            int v=it.second.second;
            
            if(ds.findUPar(u)!=ds.findUPar(v)){
                mstwt+=wt;
                ds.unionByRank(u,v);
            }
        }
        
        return mstwt;
        
    }
};