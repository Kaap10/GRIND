class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr) {
     int max_curr = arr[0];
     int max_global = arr[0];

        for(int i=1; i<arr.size(); i++) {
            max_curr = max(arr[i], max_curr + arr[i]);
            if(max_curr > max_global) {
                max_global = max_curr;
            }
        }
        return max_global;
    }
};