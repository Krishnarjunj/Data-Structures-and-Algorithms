/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    bool isleaf(Node* root){
      if(root->left == nullptr && root->right == nullptr) return true;
      return false;
    }

    void findleft(Node* root, vector<int>& ans){
      if(root==nullptr) return;

      queue<Node*> q;
      if(!isleaf(root)) q.push(root);

      while(!q.empty()){
        Node* cur = q.front();
        q.pop();
        ans.push_back(cur->data);

        if(cur->left!=nullptr){
          if(!isleaf(cur->left)) q.push(cur->left);
        }
        else if(cur->right!=nullptr){
          if(!isleaf(cur->right))   q.push(cur->right); 
        }
      }
    }

    void findleaves(Node* root, vector<int>& ans){
      if(root==nullptr) return;

      findleaves(root->left, ans);
      if(isleaf(root)) ans.push_back(root->data);
      findleaves(root->right, ans);
    }

    void findright(Node* root, vector<int>& ans){
      if(root==nullptr) return;

      stack<int> st;
      queue<Node*> q;
      if(!isleaf(root)) q.push(root);

      while(!q.empty()){
        Node* cur = q.front();
        q.pop();
        st.push(cur->data);

        if(cur->right!=nullptr){
          if(!isleaf(cur->right)) q.push(cur->right);
        }
        else if(cur->left!=nullptr){
          if(!isleaf(cur->left)) q.push(cur->left);
        }
      }
      while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
      }
    }

    vector<int> boundaryTraversal(Node *root) {
      // code here
      vector<int> ans;
      if(root == nullptr) return ans;
      ans.push_back(root->data);
      if(isleaf(root)) return ans;
      findleft(root->left, ans);
      findleaves(root, ans);
      findright(root->right, ans);

      return ans;
    }
};
