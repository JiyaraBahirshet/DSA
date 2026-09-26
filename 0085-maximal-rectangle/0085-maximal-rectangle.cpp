class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for(int i = 0; i < n; i++) {

            while(!st.empty() && heights[st.top()] > heights[i]) {

                int element = st.top();
                st.pop();

                int nse = i;
                int pse = st.empty() ? -1 : st.top();

                int width = nse - pse - 1;

                int area = heights[element] * width;

                maxArea = max(maxArea, area);
            }

            st.push(i);
        }

        // Process remaining elements
        while(!st.empty()) {

            int element = st.top();
            st.pop();

            int nse = n;
            int pse = st.empty() ? -1 : st.top();

            int width = nse - pse - 1;

            int area = heights[element] * width;

            maxArea = max(maxArea, area);
        }

        return maxArea;
    }


    int maximalRectangle(vector<vector<char>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        int maxArea = 0;

        vector<int> pSum(m, 0);

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                if(matrix[i][j] == '1') {
                    pSum[j]++;
                }
                else {
                    pSum[j] = 0;
                }
            }

            maxArea = max(maxArea, largestRectangleArea(pSum));
        }

        return maxArea;
    }
};