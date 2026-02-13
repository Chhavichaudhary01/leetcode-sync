class Solution {
public:
    bool isPerfectSquare(int num) {
        long long low = 1, high = num;

        while(low <= high) {
            long long mid = (low + high) / 2;

            if(mid == num / mid && num % mid == 0) {
                return true;
            }
            else if(mid < num / mid) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return false;
    }
};

