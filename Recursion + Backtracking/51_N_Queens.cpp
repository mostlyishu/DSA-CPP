class Solution {
public:
    bool isSafe(vector<string>&board , int row , int col , int n){
        // teen chzen check kro only ... whole col , upper left diagonal , upper right diagonal
        int i = row; // curr (i,j) index pos 
        int j = col;
        // upper column 
        while (i>=0){
          if (board[i][j]=='Q') // if queen found in upper col ^ .. can't place
          return false; 

          i--;
        }
        i =row; // reset coordinates
        j =col;

        // upper left diagonal
        while (i>=0 && j>=0){ 
            if (board[i][j]=='Q')
          return false;

          i--;
          j--;
        }
        i =row; // reset
        j =col;

        // upper right diagonal : as we have placed an QUEEN somewhere in the above rows so we also have to check for upper right diagonal
        while (i>=0 && j<board.size()){
             if (board[i][j]=='Q')
          return false;

          i--;
          j++;
        }
        // if no condition matched then .. ,
        // No queen can attack this position
        return true;  
    }
    void placeQueens(vector<string>&board , vector<vector<string>> &ans ,int n , int row){
        // base case 
        if (row>=n){ // sari rows khtm mtlb saari queens placed succesfully ... save the ans (configuration)
            ans.push_back(board);
            return;
        }

        // ek row k har col me ek baar me ek QUEEN rkh k possible arrangements bnao
        for (int col =0 ; col<board[0].size() ; col++){ // Try every column in the current row
            if (isSafe(board , row , col , n)){ // check if curr pos is safe to place
            board[row][col]= 'Q'; // place QUEEN
            placeQueens(board, ans , n , row+1); // go for next queen place in second row
            board[row][col]='.'; // backtrack to check anotgher possibility
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        // place queen row wise in each col and check safety
        vector<string> board(n, string(n, '.')); //empty n*n board
        vector<vector<string>>ans; // to store all possible configuration

        placeQueens(board , ans , n , 0); // 0 -> int. row indx .. so we will place queens row wise 

        return ans;
        
    }
};