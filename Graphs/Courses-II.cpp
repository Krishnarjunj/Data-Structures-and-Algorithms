class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& recStack, stack<int>& st) {
        vis[node] = 1;
        recStack[node] = 1;

        for (auto it : adj[node]) {
            if (vis[it] == -1) {
                if (!dfs(it, adj, vis, recStack, st)) return false;
            } else if (recStack[it]) {
                return false;  
            }
        }

        recStack[node] = 0;
        st.push(node);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }

        vector<int> vis(n, -1);
        vector<int> recStack(n, 0);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            if (vis[i] == -1) {
                if (!dfs(i, adj, vis, recStack, st)) return {};
            }
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
