class Solution {
public:
    long long cnt = 0;  // use long long for count

    void merge(vector<long long>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        // Create temp vectors
        vector<long long> L(n1), R(n2);

        // Copy data to temp vectors L[] and R[]
        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

        int i = 0, j = 0;
        int k = left;

        // Merge the temp vectors back into arr[left..right]
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        // Copy the remaining elements of L[]
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        // Copy the remaining elements of R[]
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    void CountPairs(vector<long long>& arr, int lo, int mid, int hi) {
        int right = mid + 1;
        for (int i = lo; i <= mid; i++) {
            while (right <= hi && arr[i] > 2LL * arr[right])  // 2LL for long long
                right++;
            cnt += (right - (mid + 1));
        }
    }

    void mergeSort(vector<long long>& arr, int left, int right) {
        if (left >= right)
            return;

        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        CountPairs(arr, left, mid, right);
        merge(arr, left, mid, right);
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<long long> arr(nums.begin(), nums.end()); // convert nums to long long
        mergeSort(arr, 0, n - 1);
        return (int)cnt; // final answer fits in int
    }
};
