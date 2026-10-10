
class Solution {
public:
    int countAnagrams(string s) {
        const long long MOD = 1e9 + 7;
        long long ans = 1;
        long long denominator = 1;
        int count[26] = {};
        int len = 0;

        for (char c : s) {
            if (c == ' ') {
                len = 0;
                for (int i = 0; i < 26; i++) {
                    count[i] = 0;
                }
            } else {
                len++;
                count[c - 'a']++;

                ans = ans * len % MOD;
                denominator = denominator * count[c - 'a'] % MOD;
            }
        }

        return ans * modPow(denominator, MOD - 2, MOD) % MOD;
    }

    long long modPow(long long base, long long exp, long long MOD) {
        long long result = 1;

        while (exp > 0) {
            if (exp % 2 == 1) {
                result = result * base % MOD;
            }

            base = base * base % MOD;
            exp /= 2;
        }

        return result;
    }
};
