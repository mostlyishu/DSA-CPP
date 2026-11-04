class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int beauty = 0; // to return total sum of beauty of all of substrings of s
         // generate all substr
        for ( int i = 0 ; i<n ; i++ ){
            vector<int> freq(26,0); // freq array for marking freq to cal beauty .. for every new substr from ith index
            for ( int j = i ; j<n ; j++){
                int maxFreq = INT_MIN;
                int minFreq = INT_MAX;
                freq[s[j] - 'a']++; // ek ek new char ki freq update krte jao jese jese j aage bdh rha h 
                for(int k =0;k<26;k++){
                    if(freq[k]>0){
                        maxFreq = max(freq[k],maxFreq);
                        minFreq = min(freq[k],minFreq);
                    }
                }
             beauty += maxFreq - minFreq ; // formula given
            }
        }
        return beauty;
    }
};