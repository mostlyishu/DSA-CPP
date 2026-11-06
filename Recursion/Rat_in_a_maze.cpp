class Solution {
  public:
    void helper(vector<vector<int>>& maze , int r , int c , vector<string> &ans, string temp){
        int n = maze.size();
        // base case : reached last cell
        if ( r == n-1 && c == n-1){
            ans.push_back(temp); // jo temp ans bnaya h use push krdo 
            return;
        }

        // mark cell as visited 
        maze[r][c]=-1; // jispe khde ho visited mark kro

        // aage jao koi ek direction me
        // down direction
        if ( r+1<n && maze[r+1][c]==1){
          helper ( maze , r+1 , c , ans , temp + 'D');
        }
        // left direction
        if ( c-1>=0 && maze[r][c-1]==1){
          helper ( maze , r , c-1 , ans , temp + 'L');
        }
        // right direction
        if ( c+1<n && maze[r][c+1]==1){
          helper ( maze , r , c+1 , ans , temp + 'R');
        }
        // up direction
        if ( r-1>=0 && maze[r-1][c]==1){
          helper ( maze , r-1 , c , ans , temp + 'U');
        }

        // if koi direction to move ni h ya wps aare ho doosra ans bnane toh
        // backtrack :  restore current cell
        maze[r][c] =1;

    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> ans;
        // invalid start 
        if (maze[0][0] ==0)
        return ans;

        helper(maze , 0 , 0 , ans , "");

        return ans;
    }
};