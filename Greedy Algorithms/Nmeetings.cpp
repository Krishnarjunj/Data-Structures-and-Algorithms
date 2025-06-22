class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    
    bool static comprator(pair<int,int> &a, pair<int,int> &b){
        if(a.second > b.second) return false;
        else if(a.second < b.second) return true;
        else if(a.first < b.first) return true;
        else return false;
    }
    
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        vector<pair<int,int>> meets;
        int n = start.size();
        for(int i = 0 ; i < n ; i++){
            meets.push_back({start[i], end[i]});
        }
        sort(meets.begin(), meets.end(), comprator);
        int ans = 1;
        int c = 1;
        int limit;
        for(auto it : meets){
            if(c==1){
                c++;
                limit = it.second;
                continue;
            }
            if(it.first > limit){
                ans++;
                limit = it.second;
            }
            
        }
        return ans;
        
    }
};
