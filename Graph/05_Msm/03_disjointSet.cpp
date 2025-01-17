#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank,parent;
    vector<int> size;
    public:
        DisjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            for(int i=0;i<=n;i++){
                parent[i]=i;
            }
            size.resize(n+1,1);
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

        //find union by size
        void unionBySize(int u, int v){
            int ulp_u=findUPar(u);
            int ulp_v=findUPar(v);

            if(ulp_u==ulp_v)
                return ;
            if(size[ulp_u]<size[ulp_v]){
                parent[ulp_u]=ulp_v;
                size[ulp_v]+=size[ulp_u];
            }else{
                parent[ulp_v]=ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
        }
};

int main(){
    DisjointSet ds1(7),ds2(8);
    ds1.unionByRank(1,2);
    ds1.unionByRank(2,3);
    ds1.unionByRank(4,5);
    ds1.unionByRank(6,7);
    ds1.unionByRank(5,6);

    //now find here that if 3 and 7 are a part of the same component of not ?
    if(ds1.findUPar(5)==ds1.findUPar(6))
        cout<<"5 and 6 are the same part of the same graph component"<<endl;
    else
        cout<<"5 and 6 do not have the same parent";

    return 0;
}