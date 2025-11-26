class Solution {
public:
    int countElements(vector<int>& nums) {
        int n = nums.size();
        int min = *min_element(nums.begin(),nums.end());
        int max = *max_element(nums.begin(),nums.end());
       
        int count =0;
        for(int x: nums){
            if(x>min && x<max){
                count++;
            }
        }
        
        return count;
    }
};
