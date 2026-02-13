class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
       
        vector<int>ans;
        for(int val:nums){
            ans.push_back(val*val);
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};
