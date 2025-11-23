class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        vector<int> r1; // remainder 1 wale
        vector<int> r2; // remainder 2 wale
        
        for (int x : nums) {
            sum += x;
            if (x % 3 == 1) r1.push_back(x);
            else if (x % 3 == 2) r2.push_back(x);
        }

        // Already divisible by 3
        if (sum % 3 == 0) return sum;

        // Sort remainder lists
        sort(r1.begin(), r1.end());
        sort(r2.begin(), r2.end());

        int ans = 0;
        int rem = sum % 3;

        if (rem == 1) {
            int remove1 = r1.size() > 0 ? r1[0] : 1e9;
            int remove2 = r2.size() > 1 ? r2[0] + r2[1] : 1e9;
            ans = sum - min(remove1, remove2);
        }
        else { // rem == 2
            int remove1 = r2.size() > 0 ? r2[0] : 1e9;
            int remove2 = r1.size() > 1 ? r1[0] + r1[1] : 1e9;
            ans = sum - min(remove1, remove2);
        }

        return ans;
    }
};

