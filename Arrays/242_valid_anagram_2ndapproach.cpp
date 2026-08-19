class Solution {
public:
    bool isAnagram(string s, string t) {

  if (s.size()!=t.size())
  return false;
        // frequency array approach takes O(1) SC 
  else { 
        int freq[26]={0}; // 26 blocks for alphabets freq and all init with 0 in start 
         int n =26;
        // traverse string s and record freq 
        for (int i =0 ; i<s.size() ; i++){
            freq[s[i]-'a']++; // inc freq of b , we do 'b'-'a' which is 98 - 97 in ascii and hence gives 1 and hence 1 index freq is increased 
        }

        // now traverse string t and dec freq 
        for (int i =0 ;i<t.size(); i++){
            freq[t[i]-'a']--; //-'a' is used to make a valid index in freq array ... remember this trick
        }

        // now check if any index value in freq array is one
        for (int i=0 ; i<n ; i++){
            if (freq[i]==1){
            return false;
            break;
            }
        }
        return true;
        }
    }
};