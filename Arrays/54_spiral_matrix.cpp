class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> ans; // to store ans 
        int rows = matrix.size();
        int cols = matrix[0].size();
    
        // boundaries 
        int top =0; 
        int bottom = rows-1;
        int left =0;
        int right = cols-1;    

        while (top <= bottom && left <= right) {

            // 1. left → right : top row movement
            for (int i = left ; i<= right ; i++){
                ans.push_back(matrix[top][i]);
            }
            top++; // boundary concised

            // 2. top → bottom : right col movement
            for ( int i = top ; i<=bottom ; i++){
                ans.push_back(matrix[i][right]);
            }
            right--;

            // 3. right → left (with boundary check) bottom movement
            if(top<=bottom){ //these statements prevents us from printing same elements twice 
            for ( int i = right ; i>=left ; i--){
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;}

            // 4. bottom → top (with boundary check) left movement
            if (left<=right){
            for ( int i = bottom ; i>=top ; i--){
                ans.push_back(matrix[i][left]);
            }
            left++;}
        }

        return ans;
    }
};