//815. Bus Routes
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) {
            return 0;
        }

        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < routes.size(); ++i) {
            for (int stop : routes[i]) {
                graph[stop].push_back(i);
            }
        }

        vector<bool> vis_stops(1000001, false);
        unordered_set<int> vis_routes;
        queue<pair<int, int>> q;  //{stop, number of buses}
        q.push({source, 0});

        while (!q.empty()) {
            int currStop = q.front().first;
            int busNumber = q.front().second;
            q.pop();

            if (currStop == target) {
                return busNumber;
            }

            for (int routeIndex : graph[currStop]) {
                if (vis_routes.find(routeIndex) == vis_routes.end()) {
                    vis_routes.insert(routeIndex);

                    for (int nextStop : routes[routeIndex]) {
                        if (!vis_stops[nextStop]) {
                            vis_stops[nextStop] = true;
                            q.push({nextStop, busNumber + 1});
                        }
                    }
                }
            }
        }

        return -1;
    }
};
