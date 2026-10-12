
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;

        for (string word : words) {
            freq[word]++;
        }

        vector<string> result;

        for (auto& it : freq) {
            result.push_back(it.first);
        }

        sort(result.begin(), result.end(), [&](string a, string b) {
            if (freq[a] == freq[b]) {
                return a < b;
            }
            return freq[a] > freq[b];
        });

        result.resize(k);
        return result;
    }
};
