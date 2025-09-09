class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        int div = 1;
        // Find the divisor to extract the most significant digit
        while (x / div >= 10) {
            div *= 10;
        }

        while (x > 0) {
            int left = x / div;    // Most significant digit
            int right = x % 10;    // Least significant digit

            if (left != right) return false;

            // Remove leftmost and rightmost digits
            x = (x % div) / 10;

            // After removing two digits, div reduces by factor of 100
            div /= 100;
        }

        return true;
    }
};

