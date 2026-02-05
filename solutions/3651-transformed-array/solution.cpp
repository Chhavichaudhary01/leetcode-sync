class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        for (int i = 0; i < n; i++) {
            int index = ((i + nums[i]) % n + n) % n; // safe modulo
            result.push_back(nums[index]);
        }
        return result;
    }
};

