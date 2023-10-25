//841. Keys and Rooms
//Refer LeetCode
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> vis(rooms.size(),0);
        queue<int> q;
        q.push(0);
        vis[0]=1;

        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(int i=0;i<rooms[node].size();i++){
                if(vis[rooms[node][i]]==0){
                    q.push(rooms[node][i]);
                    vis[rooms[node][i]]=1;
                }
            }
        }
        //checking unvisited 
        for(int i=0;i<vis.size();i++){
            if(vis[i]==0)
                return false;
        }
        return true;
    }
};

int main(){
    Solution s;
    vector<vector<int>> rooms = {{1},{2},{3},{0}};
    vector<vector<int>> rooms1 = {{1,3},{3,0,1},{2},{0}};
    if(s.canVisitAllRooms(rooms1)==true)
        cout<<" Can visit all the rooms"<<endl;
    else
        cout<<"Can't visit all the rooms"<<endl;
    return 0;
}