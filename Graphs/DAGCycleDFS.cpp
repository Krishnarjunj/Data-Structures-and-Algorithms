class Solution {
public:
    bool dfs(int node, stack<int>& st, vector<int>& vis, vector<vector<int>>& adj, vector<int>& recstack) {
        vis[node] = 1;
        recstack[node] = 1;

        for (auto it : adj[node]) {
            if (vis[it] == 0) {
                if (!dfs(it, st, vis, adj, recstack)) return false;
            } else if (recstack[it] == 1) {
                return false; // cycle detected
            }
        }

        recstack[node] = 0;
        st.push(node);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);  // p[1] → p[0]
        }

        vector<int> vis(numCourses, 0);
        vector<int> recstack(numCourses, 0);
        stack<int> st;

        for (int i = 0; i < numCourses; i++) {
            if (vis[i] == 0) {
                if (!dfs(i, st, vis, adj, recstack)) return {};
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
