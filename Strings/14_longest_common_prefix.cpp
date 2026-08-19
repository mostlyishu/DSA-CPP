class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) { // O(nlogn*m) approach
        string ans="";
        // empty case 
        if (strs.size()==0)
        return ans;

        // sort and compare the end words .. whatever prefix is common to first and last must be common to everything between them
        //Because after sorting, the two strings that are most different lexicographically are at the ends

        // step 1 : Sort vector strs 
        sort(strs.begin(),strs.end()); // now we need to compare only first and last string
        // as the common prefix between them would be common for all
        // match the prefix of first and last string
        string first = strs[0]; // first word after sorting
        string last = strs[strs.size()-1]; // last word after sorting 
        int i =0 ;
        while (i<first.size() && i<last.size() && first[i]==last[i]){ 
            // if first word has characters left and last word has characters left and 
            // character matches of first and last .. push it in ans and move i forward 
            ans.push_back(first[i]);
            i++;
        }
        return ans; // string formed with longest prefix commmon
    }
};
// can also be solved by checking every string O(n*m) approach 
