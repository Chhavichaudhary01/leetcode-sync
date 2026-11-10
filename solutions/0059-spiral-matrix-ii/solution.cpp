class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));

        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        int num = 1;

        while (top <= bottom && left <= right) {

            // Left to Right
            for (int i = left; i <= right; i++)
                ans[top][i] = num++;
            top++;

            // Top to Bottom
            for (int i = top; i <= bottom; i++)
                ans[i][right] = num++;
            right--;

            // Right to Left
            if (top <= bottom) {
                for (int i = right; i >= left; i--)
                    ans[bottom][i] = num++;
                bottom--;
            }

            // Bottom to Top
            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    ans[i][left] = num++;
                left++;
            }
        }

        return ans;
    }
};
