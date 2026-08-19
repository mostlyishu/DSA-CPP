class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // Step 1 : convert numbers to string bcoz we need to compare 
        vector <string>str ;
        for (int i =0 ; i<nums.size() ; i++){
               str.push_back(to_string(nums[i])); // to_string is pre defined fucntion to covert into string
        }
        // now str contains nums element as string 
        // now use sorting with custom comparator (lambda function) i.e custom sorting
        sort(str.begin(),str.end(),[](string a, string b){
            return a+b > b+a;
        });
        // this simply means Sort str, but whenever you compare two elements a and b, put a before b if ab is greater than ba else put b before a 
        // after this step largest number is formed in str just attach it in a single string 
        // but if nums wasd {0,0,0} then largest no should be 0
        string ans;
        if (str[0]=="0"){
            ans="0" ;
            
        }
        else{
        for (int i=0 ; i<str.size() ; i++){
            ans+=str[i];
           }
        }
        // now ans is the largest number that can be formed 
        return ans;
    }
};

// DRY RUN :- 
// nums
//  ↓
// [3, 30, 34, 5, 9]

// convert to strings
//  ↓
// ["3", "30", "34", "5", "9"]

// custom sort using:
// a+b > b+a
//  ↓
// ["9", "5", "34", "3", "30"]

// concatenate
//  ↓
// "9" + "5" + "34" + "3" + "30"

//  ↓

// "9534330"