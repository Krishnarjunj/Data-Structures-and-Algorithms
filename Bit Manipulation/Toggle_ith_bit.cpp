class Solution {
  public:
    int toggleBits(int n, int l, int r) {
        
        for(int i = l - 1 ; i < r ; i++){
            n = n ^ (1 << i);
        }
        
        return n;
    }
};
