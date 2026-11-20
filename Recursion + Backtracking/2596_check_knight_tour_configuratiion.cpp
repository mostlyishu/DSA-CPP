class Solution {
public:
    bool isValid(vector<vector<int>>& grid,int r, int c , int expVal){
        // base case 1
        if (r<0 || c<0 || c>=grid[0].size() || r>=grid.size() || grid[r][c] != expVal){
            return false;
        }
        // base case 2 
        if(grid[r][c]== grid.size()*grid.size() -1){ // agar m last numeric value tak valid moves se phoch paya toh true return krdo fr 
             return true;
        }

        // knight can move in 8 directions 
        bool ans1 = isValid(grid , r-2 , c+1 , expVal +1); // phle ye move hoga agr sb kuch thk h toh agli call chli jayegi wrna agli move se check hoga 
        bool ans2 = isValid(grid , r-1 , c+2 , expVal +1);
        bool ans3 = isValid(grid , r+1 , c+2 , expVal +1);
        bool ans4 = isValid(grid , r+2 , c+1 , expVal +1);
        bool ans5 = isValid(grid , r+2 , c-1 , expVal +1);
        bool ans6 = isValid(grid , r+1 , c-2 , expVal +1);
        bool ans7 = isValid(grid , r-1 , c-2 , expVal +1);
        bool ans8 = isValid(grid , r-2 , c-1 , expVal +1);

        return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8; // agr koi b ek move shi se chl paate h hum toh true h ... means or of all the ans 

    }
    bool checkValidGrid(vector<vector<int>>& grid) {

        // function to check if knight can move the whole grid by peforming the valid moves
        return isValid(grid,0,0,0);

    }
};