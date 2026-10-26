class Solution {
public:
    string getPermutation(int n, int k) {
        string numbers = "";
        vector<int> fact(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i;
            numbers += to_string(i);
        }

        k--; // Convert k to 0-based indexing
        string ans = "";

        while (n > 0) {
            int index = k / fact[n - 1];

            ans += numbers[index];
            numbers.erase(numbers.begin() + index);

            k %= fact[n - 1];
            n--;
        }

        return ans;
    }
};