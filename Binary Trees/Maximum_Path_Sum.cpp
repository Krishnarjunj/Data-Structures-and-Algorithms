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
    int findans(TreeNode* root, int& ans){
        if(root==nullptr) return 0;

        int lh = findans(root->left, ans);
        int rh = findans(root->right, ans);

        ans = max(ans, root->val + lh + rh);

        return root->val + max(lh, rh) > 0 ? root->val + max(lh, rh) : 0;
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        findans(root, ans);
        if(ans==INT_MIN) return 0;
        return ans;
    }
};
