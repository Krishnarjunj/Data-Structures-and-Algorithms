class Solution {
public:
    int x = INT_MIN;
    int y = INT_MAX;

    void findans(TreeNode* root, vector<tuple<int, int, int>> &nodes, int p, int r) {
        if (root == nullptr) return;

        x = max(x, r);
        y = min(y, r);

        nodes.push_back({r, p, root->val});

        findans(root->left, nodes, p + 1, r - 1);
        findans(root->right, nodes, p + 1, r + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;

        vector<tuple<int, int, int>> nodes;

        findans(root, nodes, 0, 0);

        sort(nodes.begin(), nodes.end()); // sorts by r, then p, then val

        int width = x - y + 1;
        ans.resize(width);

        for (auto& [r, p, val] : nodes) {
            ans[r - y].push_back(val);
        }

        return ans;
    }
};
