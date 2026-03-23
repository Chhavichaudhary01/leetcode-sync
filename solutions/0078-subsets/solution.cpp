class Solution {
public:
    void getAllSub(vector<int>& nums,vector<int>&ans,int i,vector<vector<int>>&allsubsets){
        if(i == nums.size()){
            

            //store
            allsubsets.push_back({ans});
            return;
        }
        ans.push_back(nums[i]);
        getAllSub(nums,ans,i+1, allsubsets);
        //backtracking
        ans.pop_back();
        getAllSub(nums,ans,i+1, allsubsets);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allsubsets;
        vector<int>ans;
        getAllSub(nums,ans,0,allsubsets);
        return allsubsets;
        
        
    }
};
