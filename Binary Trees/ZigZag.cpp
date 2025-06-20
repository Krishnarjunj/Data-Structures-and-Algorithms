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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool turn = false;
        TreeNode* node = root;
        while(!q.empty()){
            int n = q.size();
            vector<int> temp;
            for(int i = 0 ; i < n ; i++){
                node = q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
            }
            if(turn==true){
                reverse(temp.begin(), temp.end());
                turn = false;
            }
            else turn = true;
            ans.push_back(temp);
        }
        return ans;
    }
};
