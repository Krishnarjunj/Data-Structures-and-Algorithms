/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    int maxdepth(TreeNode* root, int &ans){
        if(root == nullptr) return 0;
        int lh = maxdepth(root->left, ans);
        int rh = maxdepth(root->right, ans);
        ans = max(lh+rh, ans);
        return 1 + max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        maxdepth(root, ans);
        return ans;
        
    }
};
