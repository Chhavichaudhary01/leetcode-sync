class Solution {
public:  
     long long power(long long a , long long b){
         long long res = 1;
         while(b){
             if(b & 1) res = res * a % 1000000007;
             a = a*a % 1000000007;
             b >>= 1;
         }
         return res;
     }
    int sumDecoded(vector<long long>& nums) {
        vector<long long> vl = nums;
        long long ans= 0;

        for(long long n: vl){
            int w = n % 10;
            long long d = n / 10;

            string s = to_string(d);
            long long x = stoll(s.substr(0, w));
            long long y = stoll(s.substr(w));

            ans = (ans + power(x , y)) % 1000000007;
        }
        return ans;
        
        
    }
};
