class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;

        // Store reserved seats of each row as a bitmask
        for (auto &x : reservedSeats) {
            mp[x[0]] |= (1 << x[1]);
        }

        long long ans = 2LL * n;

        // Seat blocks:
        // Left   -> 2,3,4,5
        // Middle -> 4,5,6,7
        // Right  -> 6,7,8,9

        int left = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
        int mid  = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
        int right = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);

        // Only rows having reservations need to be checked
        for (auto &[row, mask] : mp) {
            // We initially assumed this row can fit 2 groups
            ans -= 2;

            bool L = (mask & left) == 0;
            bool M = (mask & mid) == 0;
            bool R = (mask & right) == 0;

            if (L && R) {
                // Both side blocks are free
                ans += 2;
            }
            else if (L || M || R) {
                // At least one block is free
                ans += 1;
            }
        }

        return (int)ans;
    }
};
