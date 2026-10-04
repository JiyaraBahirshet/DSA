class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> st;

        for(int x : nums) {
            st[x]++;
        }

        int longest = 0;

        for(auto it : st) {
            int num = it.first;

            if(st.find(num - 1) == st.end()) {
                int current = num;
                int cnt = 1;

                while(st.find(current + 1) != st.end()) {
                    current++;
                    cnt++;
                }

                longest = max(longest, cnt);
            }
        }

        return longest;
    }
};