//501. Find mode in binary search tree.
//Given the root of a binary search tree (BST) with duplicates, return all the mode(s)
// (i.e., the most frequently occurred element) in it.
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
    void inorder(TreeNode* root, unordered_map<int, int>& countMap, int& maxCount) {
        if(root == nullptr)
            return;
        
        inorder(root->left, countMap, maxCount);
        countMap[root->val]++;
        maxCount = max(maxCount, countMap[root->val]);
        inorder(root->right, countMap, maxCount);
    }

public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> countMap;
        int maxCount = 0;

        // Traverse the tree and populate the countMap and maxCount
        inorder(root, countMap, maxCount);

        vector<int> modes;
        for (const auto& entry : countMap) {
            if (entry.second == maxCount) {
                modes.push_back(entry.first);
            }
        }
        return modes;
    }
};
