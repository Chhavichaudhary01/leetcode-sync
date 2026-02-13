class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>s;
        vector<int>ans;
        int n1 = nums1.size();
        int n2 = nums2.size();
        for(int i =0;i<n1;i++){
            for(int j =0;j<n2;j++){
                if(nums1[i]== nums2[j]){
                    s.insert(nums1[i]);
                    
                }

            }
        }
        for(auto it : s){
            ans.push_back(it);
        }

        return ans;
        
        
    }
};
