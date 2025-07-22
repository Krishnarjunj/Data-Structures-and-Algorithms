class Solution {
  public:
    int setKthBit(int n, int k) {
        // Code here
        //1 0 1 0
        //0 1 0 0 => 1 << k
        return (n | (1 << k));
        
    }
};
