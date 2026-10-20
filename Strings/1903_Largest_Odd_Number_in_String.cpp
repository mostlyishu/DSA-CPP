class Solution {
public:
    string largestOddNumber(string num) {
        // scan from right and if the very first odd no ecountered at some position i ... 
        //then [0....i] is the largest possible ans ... return empty string if no odd no exists

        for ( int i = num.length()-1 ; i>=0 ; i--){ // last se shuru kro
            if( (int(num[i])) % 2 != 0 ){ // odd number h  (int lgake integer convert kia bhr)
                    return num.substr(0,i+1); // indexing k according i+1 .. is line ka mtlb h 0 index se i+1 length ki substr return krdo
            }
        }
        return ""; // koi ans ni mila toh empty string return
    }
};