class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> res;
        int current = 0; // Tracks (prefix % 5)
        for (int i = 0; i < nums.size(); i++) {
            current = (current * 2 + nums[i]) % 5; // Correct binary update
            res.push_back(current == 0); // True if divisible by 5
        }
        return res;
    }
};
