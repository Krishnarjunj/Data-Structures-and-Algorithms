class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<int> indegree(V, 0);
        
        for(int i = 0 ; i < V ; i ++){
            for(auto it : edges[i]) indegree[it] ++;
        }
        
        queue<int> q;
        
        for(int i = 0 ; i < V ; i ++){
            if(indegree[i] == 0) q.push(i);
        }
        
        int c = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            c++;
            
            for(auto it : edges[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        
        if(c<V) return true;
        return false;
    }
};
