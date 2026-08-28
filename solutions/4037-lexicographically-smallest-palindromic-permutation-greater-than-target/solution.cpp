class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        int half = n / 2;

        // Frequency of characters
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        // Check whether a palindrome is possible
        int odd = 0;
        char mid = '\0';

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2) {
                odd++;
                mid = char('a' + i);
            }
        }

        if (odd > 1)
            return "";

        // Frequency for the left half
        vector<int> halfFreq(26, 0);

        for (int i = 0; i < 26; i++) {
            halfFreq[i] = freq[i] / 2;
        }

        string t = target.substr(0, half);

        // --------------------------------------------------
        // STEP 1:
        // Try using exactly target's first half.
        // --------------------------------------------------

        vector<int> cnt = halfFreq;
        string left = "";

        for (char c : t) {
            int x = c - 'a';

            if (cnt[x] == 0) {
                left = "";
                break;
            }

            cnt[x]--;
            left += c;
        }

        if (!left.empty() || half == 0) {

            string ans = left;

            // Middle character for odd length
            if (n % 2)
                ans += mid;

            string rev = left;
            reverse(rev.begin(), rev.end());

            ans += rev;

            // Equal first half can still give a greater palindrome
            if (ans > target)
                return ans;
        }

        // --------------------------------------------------
        // STEP 2:
        // Find the smallest first half greater than target half.
        // --------------------------------------------------

        for (int i = half - 1; i >= 0; i--) {

            vector<int> remaining = halfFreq;
            bool possible = true;

            // Match target prefix [0 ... i-1]
            for (int j = 0; j < i; j++) {

                int x = t[j] - 'a';

                if (remaining[x] == 0) {
                    possible = false;
                    break;
                }

                remaining[x]--;
            }

            if (!possible)
                continue;

            // Choose the smallest character greater than t[i]
            int cur = t[i] - 'a';

            for (int c = cur + 1; c < 26; c++) {

                if (remaining[c] == 0)
                    continue;

                remaining[c]--;

                string newLeft = t.substr(0, i);
                newLeft += char('a' + c);

                // Fill remaining characters in sorted order
                for (int x = 0; x < 26; x++) {
                    newLeft += string(remaining[x], char('a' + x));
                }

                // Build palindrome
                string ans = newLeft;

                if (n % 2)
                    ans += mid;

                string rev = newLeft;
                reverse(rev.begin(), rev.end());

                ans += rev;

                return ans;
            }
        }

        return "";
    }
};
