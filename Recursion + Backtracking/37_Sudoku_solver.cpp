class Solution {
public:

    // Checks whether placing 'dig' at board[row][col] is valid
    bool isSafe(vector<vector<char>>& board, int row, int col, char dig) {

        // 1. Check the entire row
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == dig) {
                return false;  // Digit already exists in this row
            }
        }

        // 2. Check the entire column
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == dig) {
                return false;  // Digit already exists in this column
            }
        }

        // 3. Find the starting row and column of the 3x3 sub-box
        int sRow = (row / 3) * 3;
        int sCol = (col / 3) * 3;

        // Check all 9 cells inside that 3x3 sub-box
        for (int i = sRow; i < sRow + 3; i++) {
            for (int j = sCol; j < sCol + 3; j++) {
                if (board[i][j] == dig) {
                    return false;  // Digit already exists in this sub-box
                }
            }
        }

        // Digit is not present in the row, column, or sub-box
        return true;
    }


    // Recursive function that tries to solve the Sudoku
    bool helper(vector<vector<char>>& board, int row, int col) {

        // Base case: All 9 rows have been completed
        if (row == 9) {
            return true;  // Sudoku is solved successfully
        }

        // Calculate the next cell's position
        int nextRow = row; // as we are traversing row wise
        int nextCol = col + 1; // on to next col to place dig

        // If the current cell is the last column, move to the first col of the next row 
        if (col == 8) {
            nextRow = row + 1;
            nextCol = 0;
        }

        // If the current cell is already filled, skip it and move to the next cell
        if (board[row][col] != '.') { // no need to place anything 
            return helper(board, nextRow, nextCol); // agle function ki call mardi return k saath
        }
        

        // If the cell is empty, try digits from 1 to 9 one by one by checking is it is safe to place there 
        for (char dig = '1'; dig <= '9'; dig++) {

            // Check whether the current digit can be placed here
            if (isSafe(board, row, col, dig)) {

                // Place the digit temporarily
                board[row][col] = dig; 

                // Recursively solve the remaining Sudoku
                if (helper(board, nextRow, nextCol)) {
                    return true;  // Keep the digit if the solution is found
                }
                // Try solving the remaining Sudoku , If it returns true, the Sudoku is solved. Keep the current digit and return true
                // If it returns false, undo the current digit.. Try the next digit 

                // Backtrack: undo the placement if it leads to no solution
                board[row][col] = '.';
            }
        }

        // No digit from 1 to 9 worked in this cell
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {

        // Start solving from the top-left cell (0, 0) by placing dig one by one if safe to place 
        helper(board, 0, 0);
    }
};