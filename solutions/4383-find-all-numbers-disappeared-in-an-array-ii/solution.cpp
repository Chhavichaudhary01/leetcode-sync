class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int l, int up) {
        set<int> s(nums.begin() , nums.end());
        vector<vector<int >> ans;

        int st = -1;
        for(int i = l;i<= up ;i++){
            if(s.find(i) == s.end()){
                if(st == -1)
                    st = i;
            }
                else{
                    if(st != -1){
                        ans.push_back({st , i - 1});
                        st = -1;
                    
                    
                    }
                }
            }
           if(st != -1){
             ans.push_back({st , up});
        
        }
        return ans;
        
    }
};
