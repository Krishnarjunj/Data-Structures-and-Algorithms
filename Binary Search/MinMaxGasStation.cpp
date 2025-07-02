class Solution {
  public:
    int dist(vector<int> &arr, long double m){
        int n = arr.size();
        int cnt = 0;
        for(int i = 1 ; i < n ; i ++){
            int val =(arr[i] - arr[i-1])/(m);
            if(arr[i]-arr[i-1] == val*m ) cnt--;
            cnt+=val;
        }
        return cnt;
    }
      
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
        int n = stations.size();
        long double low = 0;
        long double high = 0;
        
        for(int i = 1; i < n ; i ++){
            high = max(high, (long double)(stations[i]-stations[i-1]));
        }
        
        long double diff = 1e-6;
        
        while((high-low)>diff){
            long double mid = (low + high)/2.0;
            int c = dist(stations, mid);
            if(c>k) low = mid;
            else high = mid;
        }
        return high;
        
    }
};
