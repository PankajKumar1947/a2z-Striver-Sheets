//1743. Restore the previous array from Adjacent Pairs.

#include<bits/stdc++.h>
using namespace std;

vector<int> findOriginalArray(vector<vector<int>>& adjacentPairs) {
    unordered_map<int, vector<int>> adjacencyMap;

    // Populate the adjacencyMap
    for (const auto& pair : adjacentPairs) {
        int u = pair[0];
        int v = pair[1];
        adjacencyMap[u].push_back(v);
        adjacencyMap[v].push_back(u);
    }

    // Find the start point (a number with only one neighbor)
    int startPoint = 0;
    for (const auto& entry : adjacencyMap) {
        if (entry.second.size() == 1) {
            startPoint = entry.first;
            break;
        }
    }

    // Reconstruct the array using the adjacency information
    int n = adjacentPairs.size() + 1;
    vector<int> nums(n, 0);
    nums[0] = startPoint;

    // Traverse the array and fill in the remaining elements
    for (int i = 1; i < n; ++i) {
        int currentNum = nums[i - 1];
        int neighbor = adjacencyMap[currentNum][0]; // Since every pair appears exactly once
        nums[i] = neighbor;

        // Remove the used pair to avoid revisiting
        auto& neighbors = adjacencyMap[neighbor];
        neighbors.erase(remove(neighbors.begin(), neighbors.end(), currentNum), neighbors.end());
    }

    return nums;
}

int main() {
    // Example usage:
    vector<vector<int>> adjacentPairs1 = {{2, 1}, {3, 4}, {3, 2}};
    vector<int> result1 = findOriginalArray(adjacentPairs1);
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    vector<vector<int>> adjacentPairs2 = {{4, -2}, {1, 4}, {-3, 1}};
    vector<int> result2 = findOriginalArray(adjacentPairs2);
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    vector<vector<int>> adjacentPairs3 = {{100000, -100000}};
    vector<int> result3 = findOriginalArray(adjacentPairs3);
    for (int num : result3) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}


