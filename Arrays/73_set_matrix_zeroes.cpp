class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) { // O(m*n) approach

// zeroes dhundhi .. unke i aur j store kiye unhe true mark kiya ..
// fr matrix ke index p jaake mne dekha ki i ya j true h koi sa b ... agar h toh matrix[i][j]=0 rkhdo .... 

    int m = matrix.size(); // no of rows 
    int n = matrix[0].size(); // no of cols 

    // mark zeroes in bool ( rows alag , col alag )
    vector<int> rows(m , false); // m size and all init with false 
    vector<int> cols(n, false); // n size and all init with false

    // find mark zeroes and store i in rows and j in cols 
    for (int i =0 ; i<m ; i++){
        for (int j =0 ; j<n ; j++){
            if (matrix[i][j]==0){
                rows[i]=true;
                cols[j]=true;
            }
        }
    }

    // 
    for (int i =0 ; i<m ; i++){
        for ( int j=0 ; j<n ;j++){
            if (rows[i] || cols[j]){ // if i or j any exist in rows and cols
                matrix[i][j]= 0;
            }
        }
    }
        
    }
};