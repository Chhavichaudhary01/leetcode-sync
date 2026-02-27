class Solution {
public:
    bool isHappy(int n) {

        while(n != 1){
            int sum = 0;

            while(n > 0){
                int r = n % 10;
                sum = sum + r*r;
                n = n / 10;
            }

            n = sum;

            if(n == 4) return false; // cycle detect trick
        }

        return true;
    }
};
