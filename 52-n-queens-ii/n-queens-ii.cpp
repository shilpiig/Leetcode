
class Solution {
public:
    int totalNQueens(int n) {
        vector<bool> col(n, false);
        vector<bool> diag1(2 * n - 1, false);
        vector<bool> diag2(2 * n - 1, false);

        return solve(0, n, col, diag1, diag2);
    }

    int solve(int row, int n, vector<bool>& col,
              vector<bool>& diag1, vector<bool>& diag2) {
        if (row == n) {
            return 1;
        }

        int count = 0;

        for (int c = 0; c < n; c++) {
            int d1 = row - c + n - 1;
            int d2 = row + c;

            if (col[c] || diag1[d1] || diag2[d2]) {
                continue;
            }

            col[c] = diag1[d1] = diag2[d2] = true;

            count += solve(row + 1, n, col, diag1, diag2);

            col[c] = diag1[d1] = diag2[d2] = false;
        }

        return count;
    }
};
