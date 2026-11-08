
class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> parent;
    unordered_set<string> st;

    void dfs(string word, string beginWord, vector<string>& path) {
        if (word == beginWord) {
            reverse(path.begin(), path.end());
            ans.push_back(path);
            reverse(path.begin(), path.end());
            return;
        }

        for (auto p : parent[word]) {
            path.push_back(p);
            dfs(p, beginWord, path);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {

        for (auto word : wordList) {
            st.insert(word);
        }

        if (!st.count(endWord)) {
            return ans;
        }

        queue<string> q;
        q.push(beginWord);

        st.erase(beginWord);

        bool found = false;

        while (!q.empty() && !found) {
            int sz = q.size();

            unordered_set<string> used;

            for (int i = 0; i < sz; i++) {
                string word = q.front();
                q.pop();

                for (int j = 0; j < word.size(); j++) {
                    string temp = word;

                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        temp[j] = ch;

                        if (st.count(temp)) {
                            parent[temp].push_back(word);
                            used.insert(temp);

                            if (temp == endWord) {
                                found = true;
                            }
                        }
                    }
                }
            }

            for (auto word : used) {
                st.erase(word);
                q.push(word);
            }
        }

        if (found) {
            vector<string> path;
            path.push_back(endWord);

            dfs(endWord, beginWord, path);
        }

        return ans;
    }
};
