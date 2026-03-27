class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int st = 0;
        int end = nums.size() - 1;

        while(st < end){
            int sum = nums[st] + nums[end];

            if(sum == target){
                return {st+1, end+1};
            }
            else if(sum > target){
                end--;
            }
            else{
                st++;
            }
        }

        return {};
    }
};
