class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for (string op : operations) {
            if (op == "++X" || op == "X++") {
                x++; // Increment for both "++X" and "X++"
            } else if (op == "--X" || op == "X--") {
                x--; // Decrement for both "--X" and "X--"
            }
        }
        return x;
    }
};
