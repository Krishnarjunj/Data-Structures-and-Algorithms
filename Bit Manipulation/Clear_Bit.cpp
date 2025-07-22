class Solution {
  public:
    int replaceBit(int n, int k) {
        // code here.
        // 1 1 0 1
        // 0 1 0 0
        return (n & ~(1 << k));
        // 1 0 0 1
    }
};
