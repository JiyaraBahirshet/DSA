class Solution {
public:

    void solve(int idx, string &digits, string &ds,
               vector<string> &ans) {

        // All digits processed
        if(idx == digits.size()) {
            ans.push_back(ds);
            return;
        }

        string letters[] = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        int num = digits[idx] - '0';

        for(char ch : letters[num]) {

            ds.push_back(ch);

            solve(idx + 1, digits, ds, ans);

            ds.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        vector<string> ans;
        string ds;

        solve(0, digits, ds, ans);

        return ans;
    }
};