class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(); // no of rows 

        // transpose and reverse each col... OR rverse rows first and then transpose 
        for ( int i=0; i<n ; i++){
            for ( int j=i ; j<n ; j++){ // diagonal elements se leke upr wale ele ko pkd k niche walo k sath swap krado hojaega transpose 
                swap(matrix[i][j],matrix[j][i]); // j humesha i se chlta h mtlb ki humesha diagnoal se shuru hoke upper half ki trf jaega 
            }
        }

        // now reverse the rows 
        for ( int i=0 ; i<n ; i++){ // harr ek row k sare col ko reverse krdo
            int j =0 , k =n-1;
            while (j<k){
                swap(matrix[i][j],matrix[i][k]);
                j++;
                k--;
            }
        }

    }
};