//2265: Find nodes equal to average of subtree.
//Given the root of a binary tree, return the number of nodes where the value of the node is equal to the average of the values in its subtree.

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
    pair<int,int> func(TreeNode* node, int& cnt){
        if(node==NULL)
            return {0,0};
        auto lh=func(node->left,cnt);
        auto rh=func(node->right,cnt);

        int sum=lh.first+rh.first+node->val;
        int elm=lh.second+rh.second+1;

        if(sum/elm==node->val)
            cnt++;

        return {sum,elm};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int cnt=0;
        func(root,cnt);
        return cnt;
    }
};

int main(){
    TreeNode* root=new TreeNode(4);
    root->left=new TreeNode(8);
    root->left=new TreeNode(5);
    root->left->left=new TreeNode(0);
    root->left->right=new TreeNode(1);
    root->right=new TreeNode(5);
    root->right->right=new TreeNode(6);
    
    Solution s;
    cout<<"Number of nodes whose average is equal to the subtree is : "<<s.averageOfSubtree(root);
    return 0;

}