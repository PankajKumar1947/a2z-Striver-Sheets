#include<bits/stdc++.h>
using namespace std;

//721. Accounts Merge

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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DisjointSet ds(n);

        unordered_map<string,int> nodeMail;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(nodeMail.find(mail)==nodeMail.end())
                    nodeMail[mail]=i;
                else
                    ds.unionByRank(i,nodeMail[mail]);
            }
        }

        //creating the mergedmail
        vector<string> mergedMail[n];
        for(auto it:nodeMail){
            string mail=it.first;
            int node=ds.findUPar(it.second);
            mergedMail[node].push_back(mail);
        }

        //find the final answer
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(mergedMail[i].size()==0)
                continue;
            sort(mergedMail[i].begin(),mergedMail[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it: mergedMail[i])
                temp.push_back(it);
            ans.push_back(temp);
        }
        return ans;
    }
};