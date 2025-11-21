class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int> first(26, -1), last(26, -1);

        // Record first and last occurrence of each character
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (first[c] == -1)
                first[c] = i;
            last[c] = i;
        }

        int result = 0;

        // For each character as the outer character
        for (int c = 0; c < 26; c++) {
            if (first[c] == -1 || first[c] == last[c])
                continue; // Can't form length-3 palindrome

            unordered_set<char> mid;
            // Collect distinct middle characters
            for (int i = first[c] + 1; i < last[c]; i++) {
                mid.insert(s[i]);
            }

            result += mid.size();
        }

        return result;
    }
};

