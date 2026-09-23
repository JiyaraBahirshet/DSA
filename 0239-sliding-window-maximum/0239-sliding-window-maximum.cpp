class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> list;
        deque<int> dq;

        for(int i = 0; i < n; i++) {

            // Remove elements that are outside the window
            if(!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Maintain decreasing order
            while(!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            // Window is ready
            if(i >= k - 1) {
                list.push_back(nums[dq.front()]);
            }
        }

        return list;
    }
};