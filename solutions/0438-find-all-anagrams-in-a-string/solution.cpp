class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        
        int n = s.size();
        int m = p.size();

        if (m > n) return ans;

        vector<int> cntP(26, 0);
        vector<int> cntS(26, 0);

        for (char ch : p) {
            cntP[ch - 'a']++;
        }

        int left = 0;

        for (int right = 0; right < n; right++) {
            cntS[s[right] - 'a']++;

            if (right - left + 1 > m) {
                cntS[s[left] - 'a']--;
                left++;
            }

            if (right - left + 1 == m) {
                if (cntS == cntP) {
                    ans.push_back(left);
                }
            }
        }

        return ans;
    }
};
