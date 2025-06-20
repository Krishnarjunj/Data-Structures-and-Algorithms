// MY METHOD
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
    void preorder(TreeNode* node, vector<int> &ans){
        if(node == nullptr){
            ans.push_back(-1e6);
            return;
        } 

        ans.push_back(node->val);
        preorder(node->left, ans);
        preorder(node->right, ans);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> ans1;
        vector<int> ans2;
        preorder(p, ans1);
        preorder(q, ans2);
        int n = ans1.size();
        int m = ans2.size();
        if(n!=m) return false;
        for(int i = 0 ; i < n ; i ++){
            if(ans1[i]!=ans2[i]){
                return false;
            }
        }
        return true;

    }
};

// BEST METHOD
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL){
            return true;
        }
        if(p==NULL || q==NULL){
            return false;
        }

        return ((p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
};
