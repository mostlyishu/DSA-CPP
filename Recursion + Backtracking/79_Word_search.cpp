class Solution {
public:

    bool helper(vector<vector<char>>& board,string word,int i,int j,int indx,int row,int col) {
        // Base Case:
        // Agar board ke bahar chale gaye
        // ya current character word ke current character
        // ke equal nahi hai
        if (i >= row || i < 0 || j >= col || j < 0 || board[i][j] != word[indx]) {
            return false;
        }
        // Current cell ne word ka last character match kar diya → poora word mil gaya.
        if (indx == word.size() - 1) {
            return true;
        }

        // Current cell ka original character save karo
        char temp = board[i][j];
        // Current cell ko visited mark karo
        board[i][j] = '#';
        // RIGHT
        if (j + 1 < col) { 
            if (helper(board, word, i, j + 1, indx + 1,row, col)) {
                return true;
            }
        }


        // DOWN
        if (i + 1 < row) {
            if (helper(board, word,i + 1, j,indx + 1,row, col)) {
                return true;
            }
        }

         // UP
        if (i - 1 >= 0) {
                if (helper(board, word,i - 1, j,indx + 1,row, col)) {
                     return true;
            }
        }


        // LEFT
        if (j - 1 >= 0) {
            if (helper(board, word,i, j - 1,indx + 1,row, col)) {
                return true;
            }
        }


        // BACKTRACKING
        // Agar kisi bhi direction se word nahi mila,
        // to current cell ko original character se restore karo
        board[i][j] = temp;

        return false;
    }


    bool exist(vector<vector<char>>& board, string word) {

        int row = board.size();
        int col = board[0].size();

        // Word kisi bhi cell se start ho sakta hai
        // isliye har cell ko starting point bana ke try karenge
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {

                // indx = 0 means word ka first character
                if (helper(board, word, i, j, 0, row, col)) {
                    return true;
                }
            }
        }

        return false;
    }
};