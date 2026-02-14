// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int n = nums.size();
//         int sum =0;
//         int count =0;
//         for(int i =0;i<n;i++){
//             int sum =0;
//             for(int j = i;j<n;j++){
//                 sum += nums[j];
//                 if(sum ==k) count++;

//             }
//         }
//         return count;
        
//     }
// };


//*** more optimized**///
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count =0;
        vector<int>Ps(n,0);
        Ps[0] = nums[0];
        for(int i = 1; i < n; i++){

            Ps[i] = Ps[i-1] + nums[i];
        }

        unordered_map<int,int>m; //
        for(int j =0;j<n;j++){
            
            if(Ps[j]==k) count++;
            int val = Ps[j]-k;
            if(m.find(val)!= m.end()){
                count+=m[val];
            }
            if(m.find(Ps[j])==m.end()){
                m[Ps[j]] = 0;
            }
            m[Ps[j]]++;
        }
       return count;
        
    }
};
