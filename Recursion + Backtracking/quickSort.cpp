
class Solution {
public:
    int partition(vector<int>& arr, int low, int high) {

        // Step 1: First element ko pivot maan lo
        int pivotIndx = low;
        int pivotEle = arr[low];

        int count = 0;

        // Step 2: Pivot se chhote ya equal elements count karo
        // Example: arr = {5, 3, 8, 6, 2, 7, 1, 4}
        // Pivot = 5
        // 5 se chhote/equal elements = 3, 2, 1, 4
        // count = 4

        for (int i = low + 1; i <= high; i++) {
            if (arr[i] <= pivotEle) {
                count++;
            }
        }

        // Step 3: Pivot ki correct index find karo
        // rightIndx = low + count
        // = 0 + 4 = 4
        // Matlab pivot 5 index 4 par hona chahiye

        int rightIndx = low + count;

        // Pivot ko uski correct position par place karo
        swap(arr[rightIndx], arr[pivotIndx]);

        // Pivot index update karo
        pivotIndx = rightIndx;

        // Ab array:
        // {2, 3, 8, 6, 5, 7, 1, 4}
        // Pivot 5 index 4 par aa gaya

        // Step 4: Left mein smaller/equal
        // aur right mein greater elements place karo

        int i = low;
        int j = high;

        while (i < pivotIndx && j > pivotIndx) {

            // Left se aage badho jab tak elements
            // pivot se chhote ya equal hain
            while (i < pivotIndx && arr[i] <= pivotEle) {
                i++;
            }

            // Right se peeche aao jab tak elements
            // pivot se bade hain
            while (j > pivotIndx && arr[j] > pivotEle) {
                j--;
            }

            // Dono pointers galat position par ruk gaye
            // Toh un elements ko swap kar do
            if (i < pivotIndx && j > pivotIndx) {
                swap(arr[i], arr[j]);
            }
        }

        // Final array after partition:
        // {4, 3, 1, 2, 5, 7, 6, 8}
        //
        // Left of 5  = {4, 3, 1, 2}
        // Right of 5 = {7, 6, 8}
        //
        // Pivot 5 apni correct position par hai

        return pivotIndx;
    }
};

void quickSort(vector<int>& arr, int low, int high) {

        // BASE CASE:
        // Agar 0 ya 1 element bacha hai toh wo already sorted hai
        if (low >= high) {
            return;
        }

        // Pivot ko correct position par place karo
        int p = partition(arr, low, high);

        // Pivot ke LEFT part ko sort karo
        quickSort(arr, low, p - 1);

        // Pivot ke RIGHT part ko sort karo
        quickSort(arr, p + 1, high);
    }



// RECURSION DRY RUN:
//
// Initial array:
// {5, 3, 8, 6, 2, 7, 1, 4}
//
// First partition:
// {4, 3, 1, 2, 5, 7, 6, 8}
//
// Pivot = 5, index = 4
//
// Ab quickSort ke recursive calls:
//
// quickSort(arr, 0, 3);
// Left part = {4, 3, 1, 2}
//
// quickSort(arr, 5, 7);
// Right part = {7, 6, 8}
//
// Dono parts isi tarah recursively sort honge.
//
// Final sorted array:
// {1, 2, 3, 4, 5, 6, 7, 8}
