class Solution {
public:
    void findans(TreeNode* root, int lvl, vector<int>& ans){
        if(root == nullptr) return;

        if(lvl == ans.size()){
            ans.push_back(root->val);
        }

        findans(root->right, lvl + 1, ans);
        findans(root->left, lvl + 1, ans);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        findans(root, 0, ans);
        return ans;
    }
};
