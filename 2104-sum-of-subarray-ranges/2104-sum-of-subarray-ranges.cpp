class Solution {
public:

    long long sumSubarrayMins(vector<int>& nums) {
        int n = nums.size();

        vector<int> nse(n);
        vector<int> pse(n);

        stack<int> st;

        // Next Smaller Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        while (!st.empty()) {
            st.pop();
        }

        // Previous Smaller or Equal
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }

            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        long long total = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;

            total += (long long)nums[i] * left * right;
        }

        return total;
    }


    long long sumSubarrayMaxs(vector<int>& nums) {
        int n = nums.size();

        vector<int> nge(n);
        vector<int> pge(n);

        stack<int> st;

        // Next Greater Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        while (!st.empty()) {
            st.pop();
        }

        // Previous Greater or Equal
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }

            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        long long total = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - pge[i];
            long long right = nge[i] - i;

            total += (long long)nums[i] * left * right;
        }

        return total;
    }


    long long subArrayRanges(vector<int>& nums) {

        long long maximumSum = sumSubarrayMaxs(nums);
        long long minimumSum = sumSubarrayMins(nums);

        return maximumSum - minimumSum;
    }
};