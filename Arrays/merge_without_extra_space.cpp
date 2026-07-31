class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        
        // 1.Imagine one combined array.
        // 2.Compare elements at a certain gap.
        // 3.Reduce the gap.
        // 4.Handle 3 cases (A-A, A-B, B-B).
        
        // imagine combined array of lenght m+n
        int len = m+n;
        // check at a gap so that to reduce time as array are sorted 
        int gap = (len / 2) + (len % 2); 
        // gap: 9,5,3,2,1
    
        while (gap >0){ //gap loop
            int left = 0;
        int right = left + gap;
          while(right<len){ // pointer loop
            // case 1 : both indices are in arr1
            if (left < n && right < n){
                if (a[left]>a[right])
                swap(a[left],a[right]);
            }
            // case 2 : one in arr1 and one in arr2
            if (left < n && right >= n){
                if (a[left]>b[right-n])
                swap(a[left],b[right-n]);
            }
            // case 3 : both in arr2
            if (left>=n && right>=n){
                if (b[left-n]>b[right-n])
                swap(b[left-n],b[right-n]);
            }
            right++;
            left++;
        }
        if(gap==1)
        break; // stop after gap=1 is done
        gap = (gap/2) + (gap%2); 
        }
    }
};