class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int i = n - 1;

        // Skip trailing spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        int length = 0;
        // Count the last word
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;
    }
};

