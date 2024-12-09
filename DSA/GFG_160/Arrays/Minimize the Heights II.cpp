class Solution {
  public:
    int getMinDiff(vector<int>& arr, int k) {
        int n = arr.size();
        if (n == 1) return 0;

        // Step 1: Sort the array
        sort(arr.begin(), arr.end());

        // Step 2: Calculate the initial difference
        int initialDiff = arr[n - 1] - arr[0];

        // Step 3: Iterate and modify heights
        int minHeight = arr[0] + k;
        int maxHeight = arr[n - 1] - k;
        int minDiff = initialDiff;

        for (int i = 1; i < n; ++i) {
            int newMinHeight = min(minHeight, arr[i] - k);
            int newMaxHeight = max(maxHeight, arr[i - 1] + k);
            if (newMinHeight < 0) continue; // Skip if the new height is negative
            minDiff = min(minDiff, newMaxHeight - newMinHeight);
        }

        return minDiff;
    }
};