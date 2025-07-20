class Solution {
  public:
    void dfst(int node, vector<int>& vis, vector<vector<int>>& adj, stack<int>& st) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) dfst(it, vis, adj, st);
        }
        st.push(node);
    }

    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj, vector<int>& temp) {
        vis[node] = 1;
        temp.push_back(node);
        for (auto it : adj[node]) {
            if (!vis[it]) dfs(it, vis, adj, temp);
        }
    }

    int kosaraju(vector<vector<int>> &adj) {
        int V = adj.size();
        vector<int> vis(V, 0);
        stack<int> st;

        // 1. First DFS to fill stack in finish order
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfst(i, vis, adj, st);
            }
        }

        // 2. Reverse the graph
        vector<vector<int>> revadj(V);
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                revadj[it].push_back(i);
            }
        }

        // 3. DFS on reversed graph in stack order
        vector<int> viss(V, 0);
        vector<vector<int>> sccs; 

        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!viss[node]) {
                vector<int> temp;
                dfs(node, viss, revadj, temp);
                sccs.push_back(temp);  
            }
        }

        // 🔁 Print SCCs (optional debug output)
        /*
        for (auto& comp : sccs) {
            for (int node : comp) cout << node << " ";
            cout << endl;
        }
        */

        return sccs.size(); 
    }
};
