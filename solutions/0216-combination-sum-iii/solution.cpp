class Solution {
public:
    void helper(int k, int n, int idx, vector<vector<int>> &ans, vector<int> &combin, vector<int> &nums) {
        
        // base case
        if (k == 0 && n == 0) {
            ans.push_back(combin);
            return;
        }
        
        if (k == 0 || n < 0) return;

        for (int i = idx; i < nums.size(); i++) {
            combin.push_back(nums[i]);

            helper(k - 1, n - nums[i], i + 1, ans, combin, nums);

            // backtrack
            combin.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> combin;
        vector<int> nums = {1,2,3,4,5,6,7,8,9};

        helper(k, n, 0, ans, combin, nums);
        return ans;
    }
};

