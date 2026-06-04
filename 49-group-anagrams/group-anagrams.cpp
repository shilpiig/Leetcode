class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        vector<bool> visited(n, false);
        vector<vector<string>> result;

        for (int i = 0; i < n; i++) {
            if (visited[i])
                continue;

            vector<string> group;
            group.push_back(strs[i]);
            visited[i] = true;

            string s1 = strs[i];
            sort(s1.begin(), s1.end());

            for (int j = i + 1; j < n; j++) {
                if (visited[j])
                    continue;

                if (strs[i].size() != strs[j].size())
                    continue;

                string s2 = strs[j];
                sort(s2.begin(), s2.end());

                if (s1 == s2) {
                    group.push_back(strs[j]);
                    visited[j] = true;
                }
            }

            result.push_back(group);
        }

        return result;
    }
};
