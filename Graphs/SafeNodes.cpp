class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> rev(n);
        for(int i = 0 ; i < n ; i ++){
            for(auto it : graph[i]){
                rev[it].push_back(i);
            }
        }

        vector<int> indegree(n, 0);

        for(int i = 0 ; i < n ; i ++){
            for(auto it : rev[i]){
                indegree[it]++;
            }
        }

        queue<int> q;
        vector<int> ans;

        for(int i = 0 ; i < n ; i ++){
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : rev[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
