class Encrypter {
public:
    unordered_map<char, string> encryptMap;
    unordered_map<string, int> freq;

    Encrypter(vector<char>& keys, vector<string>& values,
              vector<string>& dictionary) {

        for (int i = 0; i < keys.size(); i++) {
            encryptMap[keys[i]] = values[i];
        }

        for (string word : dictionary) {
            string encrypted = encrypt(word);

            if (encrypted != "") {
                freq[encrypted]++;
            }
        }
    }

    string encrypt(string word1) {
        string result = "";

        for (char c : word1) {
            if (encryptMap.find(c) == encryptMap.end()) {
                return "";
            }

            result += encryptMap[c];
        }

        return result;
    }

    int decrypt(string word2) {
        return freq[word2];
    }
};