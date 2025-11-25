class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0) return -1;

        int n = 0;
        int length = 0;

        // We try at most k steps (Pigeonhole principle)
        for (int i = 1; i <= k; i++) {
            n = (n * 10 + 1) % k;
            length++;

            if (n == 0) return length;
        }

        return -1;
    }
};

