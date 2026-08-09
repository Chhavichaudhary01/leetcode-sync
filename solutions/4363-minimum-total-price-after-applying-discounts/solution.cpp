class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        double ans = 0;
        int n = prices.size();
        int m = discounts.size();
        sort(prices.begin(),prices.end());
        sort(discounts.rbegin(),discounts.rend());
        for(int i =0;i<n;i++){
           if(i<m){
               ans+= prices[n -1-i] * (100.0 - discounts[i]) /100.0;
               
               
           }else{
               ans+= prices[n-1- i];
           }
        }
        return ans;
        
    }
};
