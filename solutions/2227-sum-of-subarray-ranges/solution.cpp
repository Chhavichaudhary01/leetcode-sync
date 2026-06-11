class Solution {
public:

    vector<int> prevSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ps(n);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] > nums[i])
                st.pop();

            ps[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return ps;
    }

    vector<int> nextSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ns(n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] >= nums[i])
                st.pop();

            ns[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return ns;
    }

    vector<int> prevGreater(vector<int>& nums) {
        int n = nums.size();
        vector<int> pg(n);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] < nums[i])
                st.pop();

            pg[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return pg;
    }

    vector<int> nextGreater(vector<int>& nums) {
        int n = nums.size();
        vector<int> ng(n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] <= nums[i])
                st.pop();

            ng[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return ng;
    }

    long long subArrayRanges(vector<int>& nums) {

        int n = nums.size();

        vector<int> ps = prevSmaller(nums);
        vector<int> ns = nextSmaller(nums);

        vector<int> pg = prevGreater(nums);
        vector<int> ng = nextGreater(nums);

        long long minSum = 0;
        long long maxSum = 0;

        for(int i = 0; i < n; i++) {

            long long leftMin = i - ps[i];
            long long rightMin = ns[i] - i;

            minSum += 1LL * nums[i] * leftMin * rightMin;

            long long leftMax = i - pg[i];
            long long rightMax = ng[i] - i;

            maxSum += 1LL * nums[i] * leftMax * rightMax;
        }

        return maxSum - minSum;
    }
};
