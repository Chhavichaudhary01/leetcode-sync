class Solution {
public:
    vector<int> f( int x){
        vector<int>a;
        for(int p = 2; p*p <=x ; p++){
            if(x % p ==0){
                a.push_back(p);
                while(x% p == 0) x/=p;
            }
           
        }
        if(x>1) a.push_back(x);
        return a;
    }
    int longestSubarray(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        int l = 0 , ans = 0 , d = 0;
        for(int r = 0 ;r<nums.size();r++){
            for(int p :f(nums[r]))
                if(mp[p] ++ == 0) d++;
            while(d>k){
                for(int p :f(nums[l]))
                    if(--mp[p] == 0) d--;
                l++;
            }
            ans = max(ans , r- l + 1);
        }
        return ans;
        
    }
};
