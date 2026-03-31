class Solution {
public:
    string minWindow(string s, string t) {
    unordered_map<char, int> need;

    for(char c : t) need[c]++;

    int left = 0, count = 0;
    int minLen = INT_MAX, start = 0;

    for(int right = 0; right < s.size(); right++) {
        char c = s[right];

        if(need[c] > 0) count++;  
        need[c]--;

        while(count == t.size()) {
            if(right - left + 1 < minLen) {
                minLen = right - left + 1;
                start = left;
            }

            need[s[left]]++;
            if(need[s[left]] > 0) count--;

            left++;
        }
    }

    return minLen == INT_MAX ? "" : s.substr(start, minLen);
}
};
