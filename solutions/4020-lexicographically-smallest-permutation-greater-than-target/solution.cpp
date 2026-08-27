class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        // Frequency of characters in s
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        string ans;

        // Try to match target from left to right
        for (int i = 0; i < n; i++) {
            int x = target[i] - 'a';

            // We can keep the same character
            if (freq[x] > 0) {
                ans += target[i];
                freq[x]--;
            }
            else {
                // We cannot match target[i].
                // Try making the current position greater.
                int bigger = -1;

                for (int c = x + 1; c < 26; c++) {
                    if (freq[c] > 0) {
                        bigger = c;
                        break;
                    }
                }

                if (bigger != -1) {
                    ans += char('a' + bigger);
                    freq[bigger]--;

                    // Remaining characters in sorted order
                    for (int c = 0; c < 26; c++) {
                        while (freq[c] > 0) {
                            ans += char('a' + c);
                            freq[c]--;
                        }
                    }

                    return ans;
                }

                break;
            }
        }

        // We matched a prefix equal to target.
        // Now backtrack and try to make an earlier position bigger.

        for (int i = ans.size() - 1; i >= 0; i--) {
            // Put ans[i] back
            freq[ans[i] - 'a']++;

            int x = target[i] - 'a';

            // Find smallest character > target[i]
            for (int c = x + 1; c < 26; c++) {
                if (freq[c] > 0) {
                    string res = ans.substr(0, i);

                    // Make this position greater
                    res += char('a' + c);
                    freq[c]--;

                    // Fill remaining positions with smallest chars
                    for (int j = 0; j < 26; j++) {
                        while (freq[j] > 0) {
                            res += char('a' + j);
                            freq[j]--;
                        }
                    }

                    return res;
                }
            }
        }

        return "";
    }
};

