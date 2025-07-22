class Solution {
  public:
    bool checkKthBit(int n, int k) {
        //  code here
        // METHOD 1
        if((n  & (1 << k)) != 0) return true;
        return false;
        
        //METHOD 2
        if(((n >> k) & 1) != 0) return true;
        return false;
        
    }
};
