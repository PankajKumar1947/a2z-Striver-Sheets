#include<iostream>
#include<vector>
#include<math.h>
#include<queue>
using namespace std;

//1. Counting Graph: Return the number of graphs that can be formed from N Vertices
int countingGraphs(int N)
{
    if(N<0){
        return 0;//invalid input
    }

    // For each pair of nodes (i, j), there are 2 possibilities: edge or no edge.
    // So, the total number of graphs is 2^(N*(N-1)/2).
    
    return pow(2,N*(N-1)/2);
}

//2.Creating and Printing the graph

//3.

//4.Connected Components

//5.BFS Traversals
vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    vector<int>bfs;//vector to store ans
    vector<int> vis(n,0);//creating visited array and initialising with 0

    queue<int> q;//
    q.push(0);//as starting from the vertex 0 so push it in queue first
    vis[0]=1;//marking the first

    while(!q.empty()){
        int node=q.front();
        q.pop();

        bfs.push_back(node);
        
        //traversing the all connectins of the given node
        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
    }
    return bfs;
}

//6.DFS Traversals




int main(){
    return 0;
}