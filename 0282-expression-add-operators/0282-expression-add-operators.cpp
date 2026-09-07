class Solution {
public:

    void solve(int index, string num, long long target,
               string expression, long long value,
               long long prev,
               vector<string>& ans) {

        // We have used all digits
        if (index == num.size()) {

            if (value == target) {
                ans.push_back(expression);
            }

            return;
        }

        // Try every possible number starting from index
        for (int i = index; i < num.size(); i++) {

            // Leading zero is not allowed
            if (i > index && num[index] == '0') {
                break;
            }

            // Create current number
            string str = num.substr(index, i - index + 1);

            long long curr = stoll(str);

            // First number
            if (index == 0) {

                solve(i + 1, num, target,
                      str, curr, curr, ans);
            }

            else {

                // Addition
                solve(i + 1, num, target,
                      expression + "+" + str,
                      value + curr,
                      curr,
                      ans);

                // Subtraction
                solve(i + 1, num, target,
                      expression + "-" + str,
                      value - curr,
                      -curr,
                      ans);

                // Multiplication
                solve(i + 1, num, target,
                      expression + "*" + str,
                      value - prev + prev * curr,
                      prev * curr,
                      ans);
            }
        }
    }

    vector<string> addOperators(string num, int target) {

        vector<string> ans;

        solve(0, num, target, "", 0, 0, ans);

        return ans;
    }
};