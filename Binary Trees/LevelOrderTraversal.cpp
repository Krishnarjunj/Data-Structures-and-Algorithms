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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root == nullptr) return ans;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            vector<int> temp;
            for(int i = 0 ; i < n ; i++){
                TreeNode* root = q.front();
                if(root->left != NULL) q.push(root->left);
                if(root->right != NULL) q.push(root->right);
                temp.push_back(root->val);
                q.pop();
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
