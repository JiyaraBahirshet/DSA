
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(128, 0);

        for (char c : t) {
            freq[c]++;
        }

        int l = 0;
        int count = t.size();
        int minLen = INT_MAX;
        int start = 0;

        for (int r = 0; r < s.size(); r++) {
            if (freq[s[r]] > 0) {
                count--;
            }
            freq[s[r]]--;

            while (count == 0) {
                int len = r - l + 1;

                if (len < minLen) {
                    minLen = len;
                    start = l;
                }

                freq[s[l]]++;

                if (freq[s[l]] > 0) {
                    count++;
                }

                l++;
            }
        }

        if (minLen == INT_MAX) {
            return "";
        }

        return s.substr(start, minLen);
    }
};