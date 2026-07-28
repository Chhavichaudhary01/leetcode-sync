class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);

        // Count frequency of each character
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        string left = "";
        string mid = "";

        // Build the left half and find the middle character (if any)
        for (int i = 0; i < 26; i++) {
            left += string(freq[i] / 2, char('a' + i));

            if (freq[i] % 2 == 1) {
                mid = char('a' + i);
            }
        }

        // Right half is the reverse of left half
        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};
