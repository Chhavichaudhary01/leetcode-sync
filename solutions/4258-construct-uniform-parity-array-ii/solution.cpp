class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mnOdd = INT_MAX;
        int mnEven = INT_MAX;

        for(int x : nums1) {
            if(x % 2 == 0)
                mnEven = min(mnEven, x);
            else
                mnOdd = min(mnOdd, x);
        }

        // Already all even
        if(mnOdd == INT_MAX)
            return true;

        // Make every element odd
        return mnOdd < mnEven;
    }
};
