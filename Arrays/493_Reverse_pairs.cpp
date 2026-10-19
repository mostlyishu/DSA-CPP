class Solution { //*** VERY VERY IMPORTANT HARD QUES ***
public:
  void merge(vector<int>& nums, int low, int mid, int high) {
    vector<int> temp; // temp array to merge choti arrays temporarily

    int left = low; // left ka shuru ka ptr
    int right = mid + 1; // right ke shuru ka ptr 

    // 1. Compare elements while both halves have elements
    while (left <= mid && right <= high) { // normal merge two sorted arrays logic 
       if (nums[left]<= nums[right]){
            temp.push_back(nums[left]);
            left++;
        }
    else {
            temp.push_back(nums[right]);
            right++;
    }
}

    // 2. Copy remaining elements from left half
while (left<=mid){
temp.push_back(nums[left]);
left++;
}
    // 3. Copy remaining elements from right half
while (right<=high){
temp.push_back(nums[right]);
right++;
}
    // 4. Copy temp back to nums[low...high]
for(int i =low ; i<=high;i++){ // ye jo temp arr bni h wo bs low se high jo a₹aye the wha tk bni thi 
nums[i]=temp[i-low]; // hence temp[0],temp[1]... but nums[low].. nums[high]
    }
}

int countPairs(vector<int>& nums, int low, int mid, int high) {
    int count = 0; // intially local count zero between two halves 
    int j = mid + 1; // doosre half k starting me place krdia

    for (int i = low; i <= mid; i++) { // phle half ko traverse kro
        while (j <= high && nums[i] > 2LL * nums[j]) { //doosre half me check krte jao konse j tk satisfy hori h condition
            j++;
        }
        count += j - (mid + 1); // wo j count m plus krdo 
        // MAIN CATCH : j reset krne ki jarurat nai h kyuki if j yha tk aagya piche k elements se hi to agel wale se toh satisfy kr hi dega and also both halves are sorted VISUALISE IT 
    }
return count; // sara local count return krdo iss part ka
}

int mergesort(vector<int>& nums, int low , int high){
    // iss wale part me recursively todne ki zimmedari h 
    // base case 
    if (low>=high) // single element bacha h ab 
    return 0;

    // recursive calls 
    int mid = (low + high)/2;
    int count = 0;
    // teen part calculate honge 
    // left half individually (within)
    count = count + mergesort(nums , low , mid);
    // right half individually (within)
    count = count + mergesort(nums , mid+1 , high);

    // now between both halves combined (inter)
    count = count + countPairs(nums , low , mid , high);

    //Notice that every recursive call has its own local count. When it finishes, it returns that count to its parent.

    // now merge both sorted halves
    merge(nums, low , mid , high);
    return count; //ans finally (contains all local counts from all fucntions)
}
    int reversePairs(vector<int>& nums) {
        int n = nums.size ();
        int low = 0 ;
        int high = n-1;

        int totalcount = mergesort(nums , low , high);
        // sab jgh se count aake plus hoke mergesort me se return hore h 
        
        return totalcount;
    }
};