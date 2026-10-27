class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int maxCount = 0; // to store no of counts of all palindromic substrings 

        for (int i =0; i<s.length() ;i++){
            // odd length palindromic substrings 
            int left = i; // for odd left at i and right at i 
            int right = i; // and centre at i
            int count = 0;
            while (left >=0 && right<n && s[left]==s[right]){ // jab tk left ya right out of bound na hojaye 
            // ya fr char mismatch na hojaye expand kro and count bdhate jao .. mtlb ki hume valid palindromic substr mil rhi h 
                left--;
                right++;
                count++;
            }
            maxCount += count; // jitni mili unko plus krdo global ans me 

            //even length palindromic substrings 
            left = i; // for even left at i and right at i+1;
            right = i+1; // and centre is space between them .. expand around this centre
            count =0; // reset count now for even palindromic substring
            while (left >=0 && right<n && s[left]==s[right]){
                left--; 
                right++;
                count++; // count bdhate jao
            }
            maxCount += count; // last me fr se global ans me plus krdo
        }
        return maxCount; // global ans return krdo
    }
};