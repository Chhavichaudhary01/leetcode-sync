class Solution {
public:
    void helper(vector<int>& nums, int i, int target, 
                vector<vector<int>>& ans, vector<int>& combinSum) {
        
        if(target == 0){
            ans.push_back(combinSum);
            return;
        }
        
        if(i == nums.size() || target < 0) return;

        // include
        combinSum.push_back(nums[i]);
        helper(nums, i+1, target - nums[i], ans, combinSum);
        combinSum.pop_back();

        // skip duplicates for exclusion
        int j = i;
        while(j + 1 < nums.size() && nums[j] == nums[j+1]) j++;

        // exclusion
        helper(nums, j+1, target, ans, combinSum);
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());  // ⭐ important
        
        vector<vector<int>> ans;
        vector<int> combinSum;

        helper(nums, 0, target, ans, combinSum);

        return ans;
    }
};
