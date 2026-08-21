class Solution {
public:
    vector<string> ans;

    bool isValid(string part) {
        // Leading zero
        if (part.size() > 1 && part[0] == '0')
            return false;

        // Convert to number
        int num = stoi(part);

        return num <= 255;
    }

    void solve(string &s, int index, int parts, string current) {
        // We have created 4 parts
        if (parts == 4) {
            if (index == s.size()) {
                current.pop_back(); // remove last '.'
                ans.push_back(current);
            }
            return;
        }

        // Try taking 1, 2 or 3 digits
        for (int len = 1; len <= 3; len++) {

            // Don't go outside string
            if (index + len > s.size())
                break;

            string part = s.substr(index, len);

            // Check whether this part is valid
            if (!isValid(part))
                continue;

            solve(s, index + len, parts + 1,
                  current + part + ".");
        }
    }

    vector<string> restoreIpAddresses(string s) {
        ans.clear();

        solve(s, 0, 0, "");

        return ans;
    }
};
