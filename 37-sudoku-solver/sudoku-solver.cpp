
class Solution {
public:
    bool solveSudokuHelper(vector<vector<char>>& board) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {

                if (board[r][c] == '.') {
                    for (char num = '1'; num <= '9'; num++) {

                        if (isValid(board, r, c, num)) {
                            board[r][c] = num;

                            if (solveSudokuHelper(board))
                                return true;

                            board[r][c] = '.';
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }

    bool isValid(vector<vector<char>>& board,
                 int row, int col, char num) {

        for (int i = 0; i < 9; i++) {
            if (board[row][i] == num ||
                board[i][col] == num) {
                return false;
            }
        }

        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;

        for (int r = startRow; r < startRow + 3; r++) {
            for (int c = startCol; c < startCol + 3; c++) {
                if (board[r][c] == num)
                    return false;
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solveSudokuHelper(board);
    }
};
