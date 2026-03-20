class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int x: nums){
            mp[x]++;
        }
        int ans = 0;
        for(auto it :mp){
            if(it.second==1){
                ans+= it.first;
            }
        }
        return ans;
    }
};
