class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int , int> first , last;
        unordered_set<int> s;

        for(int i = 0 ;i< nums.size();i++){
            if(!s.count(nums[i]))
                first[nums[i]] = i;
            last[nums[i]] = i;
            s.insert(nums[i]);
        }
        
        
        int ans = 0;

        for(auto x : s){
            bool ok = true;
            for(int i = first[x]; i<= last[x]; i++){
                if(nums[i] != x){
                    ok = false;
                    break;
                }
            }
            if(ok) ans++;
        }

        return ans;
        
        
    }
};
