class Solution {
public:

    // Dono sorted halves ko merge karo
    int merge(vector<int>& arr, int s, int e, int mid) {
        vector<int> temp;
        int i = s;
        int j = mid + 1;
        int invCount = 0; // to count inversion between two halves
        
        while (i <= mid && j <= e) {

            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i++]);
            }
            else {
                temp.push_back(arr[j++]);

                // Left ke remaining elements inversions banayenge
                invCount += (mid - i + 1);
            }
        }

        // Bache hue elements copy karo
        while (i <= mid) {
            temp.push_back(arr[i++]);
        }

        while (j <= e) {
            temp.push_back(arr[j++]);
        }

        // Sorted array original mein copy karo
        for (int indx = 0; indx < temp.size(); indx++) {
            arr[s + indx] = temp[indx];
        }

        return invCount; // jo inn do halves me inv count mile return krdo 
    }


    // Merge Sort se inversions count karo
    int mergeSort(vector<int>& arr, int s, int e) {

        // Base case
        if (s >= e) {
            return 0;
        }

        int mid = s + (e - s) / 2;

        // Left aur right inversions alg se count kro in their respective calls
        // These counts are the count possible in individual half
        int leftCount = mergeSort(arr, s, mid);
        int rightCount = mergeSort(arr, mid + 1, e);

        // Cross inversions .. in two halves .. counted while merging
        int currInvCount = merge(arr, s, e, mid);

        // Total inversions
        return leftCount + rightCount + currInvCount;
    }

    int inversionCount(vector<int>& arr) {
        return mergeSort(arr, 0, arr.size() - 1);
    }
};