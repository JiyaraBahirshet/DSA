class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;

        long long curr = 1;
        ans.push_back(curr);

        for (int i = 0; i < rowIndex; i++) {
            curr = curr * (rowIndex - i) / (i + 1);
            ans.push_back(curr);
        }

        return ans;
    }
};