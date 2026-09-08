class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // push in unordered set to find later 
        unordered_set<int>st(nums.begin(),nums.end()); // whole array pushed in one go
        int maxlen = 0; // to count max long sequence len

        for (auto x : st){ // traverse set se , x is element here
            if (st.find(x-1) == st.end()){ // agar 1 k liye 0 ni milta set m 
                int start = x; // toh 1 ko start bnado
                int longest = 1; // length ek se plus krdo kykui ek toh mil gya h na 
                while (st.find(start+1)!=st.end()){ // jabtk sequence mile jaara h 
                    start++; //1->2->3->4...
                    longest++; //+1+1+1+1...
                }
                maxlen = max(maxlen,longest); // update max 
            }

            // else statement is not needed here as if an element doesn't become start it will definintely 
            // be a part of some sequence ... so later we will encounter that sequence's start
        }
        return maxlen;
        }

        // every element would either be start of sequence or part of some sequence 
};