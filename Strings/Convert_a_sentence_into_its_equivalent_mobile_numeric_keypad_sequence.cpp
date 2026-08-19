string printSequence(string S) {
    // make a string of keypad presses of each alphabet
   string keypad[26] = {"2","22","222","3","33","333",
             "4","44","444","5","55","555","6","66","666",
      "7","77","777","7777","8","88","888","9","99","999","9999"}; 
      // full keypad presses for each upper case alphabet from 0 to 25
      
      string ans =""; // stores the output 
      // traverse the input string S
      for (int i =0 ; i<S.size() ; i++){
          // space case ko handle kro alag se 
          if (S[i]==' '){
              ans.push_back('0'); // if space h toh alag se 0 push krdo ans m 
            }
          else{
          // otherwise find index
          int alphabetIndex = S[i] - 'A'; // makes index of every character by subtracting ascii value of 'A'
          // 'A' stand on 0
          // got to that index in keypad and add the numeric presses in ans as string 
          ans += keypad[alphabetIndex]; // no push_back fucntion used here 
          // as pushback function is only valid for one character not a string .. here we add whole string
              }
         }
      return ans;
    }