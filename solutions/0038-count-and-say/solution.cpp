class Solution {
public:
    string countAndSay(int n) {

        string ans = "1";

        for (int k = 2; k <= n; k++) {

            string temp = "";
            int i = 0;

            while (i < ans.size()) {

                int count = 1;

                while (i + 1 < ans.size() && ans[i] == ans[i + 1]) {
                    count++;
                    i++;
                }

                temp += to_string(count);
                temp += ans[i];

                i++;
            }

            ans = temp;
        }

        return ans;
    }
};
