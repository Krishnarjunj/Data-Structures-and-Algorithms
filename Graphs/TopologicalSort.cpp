class Solution {
  public:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& edges, stack<int>& st){
        vis[node] = 1;
        for(auto it : edges[node]){
            if(vis[it] == -1) dfs(it, vis, edges, st);
        }
        st.push(node);
    }
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> vis(V, -1);
        stack<int> st;
        for(int i = 0 ; i < V ; i ++){
            if(vis[i]==-1) dfs(i, vis, edges, st);
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
