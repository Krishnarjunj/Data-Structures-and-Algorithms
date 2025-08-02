class Solution {
  public:
    long subarrayXor(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        int count = 0;
        int xor_sum = 0;

        for (int i = 0; i < arr.size(); i++) {
            xor_sum ^= arr[i];
            if (xor_sum == k) count++;
            if (freq.find(xor_sum ^ k) != freq.end()) {
                count += freq[xor_sum ^ k];
            }
            freq[xor_sum]++;
        }

        return count;
    }
};
