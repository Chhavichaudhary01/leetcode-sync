class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> suf(n + 1, 0);

        // suf[i] = maximum number of characters
        // of word2 that can be matched from word1[i...]
        int j = m - 1;

        for (int i = n - 1; i >= 0; i--) {
            if (j >= 0 && word1[i] == word2[j]) {
                j--;
            }
            suf[i] = m - 1 - j;
        }

        vector<int> ans;
        int p = 0;
        bool changed = false;

        for (int i = 0; i < n && p < m; i++) {

            // Case 1: exact match
            if (word1[i] == word2[p]) {
                ans.push_back(i);
                p++;
            }

            // Case 2: use our one allowed modification
            else if (!changed) {

                // After changing word1[i] to word2[p],
                // remaining characters must be matchable.
                if (suf[i + 1] >= m - p - 1) {
                    ans.push_back(i);
                    p++;
                    changed = true;
                }
            }
        }

        if (p != m)
            return {};

        return ans;
    }
};
