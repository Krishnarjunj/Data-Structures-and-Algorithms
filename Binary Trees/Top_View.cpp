/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        vector<int> ans;
        if(root==nullptr) return ans;

        map<int,int> mp;

        queue<pair<Node*, int>> q;
        q.push({root, 0});

        while(!q.empty()){
          Node* cur = q.front().first;
          int lvl = q.front().second;
          if(mp.find(lvl) == mp.end()) mp[lvl] = cur->data;
          q.pop();

          if(cur->left!=nullptr) q.push({cur->left, lvl - 1});
          if(cur->right!=nullptr) q.push({cur->right, lvl + 1});

        }

        for(auto it : mp){
          ans.push_back(it.second);
        }

        return ans;

        
    }
};
