//94. Binary Tree Inorder Traversal
#include<bits/stdc++.h>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
      //recursive: Inorder=left + root + right
        vector<int> ans;
        if(root==NULL)
          return ans;
        
        //left call
        vector<int> leftSubtree=inorderTraversal(root->left);
        //left store
        ans.insert(ans.end(),leftSubtree.begin(),leftSubtree.end());

        //root store
        ans.push_back(root->val);


        //right call
        vector<int> rightSubtree=inorderTraversal(root->right);
        //right store
        ans.insert(ans.end(),rightSubtree.begin(),rightSubtree.end());

        return ans;
        
    }
};