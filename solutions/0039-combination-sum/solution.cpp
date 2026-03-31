class Solution {
public:
    set<vector<int>>s;
    void helper(vector<int>& arr,int i,vector<int>&combin,vector<vector<int>>&ans,int tar)
    {  
        //base case
        if(i==arr.size() || tar<0) return;
        if(tar ==0){
            if(s.find(combin)==s.end()){
                ans.push_back(combin);
                s.insert(combin);
                return;
            }
        }

        combin.push_back(arr[i]);
        //single inclusion
        helper(arr,i+1,combin,ans,tar-arr[i]);
        //multiple inclusion
        helper(arr,i,combin,ans,tar-arr[i]);
        // backtaracking for exclusion
        combin.pop_back();
        //exclusion call
        helper(arr,i+1,combin,ans,tar);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int tar) {
        vector<int>combin;
        vector<vector<int>>ans;
        helper(arr,0,combin,ans,tar);
        return ans;

        
    }
};
