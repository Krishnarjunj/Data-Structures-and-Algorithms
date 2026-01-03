class Solution {
public:
    long long solve(int r, int c) {
        int n = r - 1;
        int k = c - 1;

        long long result = 1;
        for (int i = 0; i < k; i++) {
            result *= (n - i);
            result /= (i + 1);
        }

        return result;
    }
};

