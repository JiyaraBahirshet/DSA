class Solution {
public:
    void findcombination(int idx, int target, vector<int>& arr,
                         vector<vector<int>>& ans, vector<int>& ds) {

        if(target == 0) {
            ans.push_back(ds);
            return;
        }

        for(int i = idx; i < arr.size(); i++) {

            // Skip duplicate elements at the same recursion level
            if(i > idx && arr[i] == arr[i - 1])
                continue;

            // Since array is sorted
            if(arr[i] > target)
                break;

            ds.push_back(arr[i]);

            // Move to next index because each element can be used only once
            findcombination(i + 1, target - arr[i], arr, ans, ds);

            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> ds;

        findcombination(0, target, candidates, ans, ds);

        return ans;
    }
};