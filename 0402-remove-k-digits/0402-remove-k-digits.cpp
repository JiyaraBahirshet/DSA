class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        
        int n = num.length();

        for(int i = 0; i < n; i++) {

            while(!st.empty() && k > 0 && st.top() > num[i]) {
                st.pop();
                k--;
            }

            st.push(num[i]);
        }

        // Remove remaining digits from the end
        while(k > 0) {
            st.pop();
            k--;
        }

        // Build result
        string result = "";

        while(!st.empty()) {
            result += st.top();
            st.pop();
        }

        // Stack gives reverse order
        reverse(result.begin(), result.end());

        // Remove leading zeroes
        int i = 0;

        while(i < result.size() && result[i] == '0') {
            i++;
        }

        result = result.substr(i);

        if(result.empty()) {
            return "0";
        }

        return result;
    }
};