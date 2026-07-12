class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>temp = arr;
        sort(temp.begin(),temp.end());
        int rank =1;
        unordered_map<int,int> mp;
        for(int x : temp){
            if(mp.find(x)==mp.end()){
                mp[x] = rank++;
            }

        }

        for(int i =0;i<arr.size();i++){
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};
