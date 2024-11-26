#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// Function to find the maximum subarray sum using Kadane's algorithm
int kadaneMax(const vector<int>& arr) {
    int max_ending_here = arr[0];
    int max_so_far = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        max_ending_here = max(arr[i], max_ending_here + arr[i]);
        max_so_far = max(max_so_far, max_ending_here);
    }
    return max_so_far;
}

// Function to find the minimum subarray sum using Kadane's algorithm
int kadaneMin(const vector<int>& arr) {
    int min_ending_here = arr[0];
    int min_so_far = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        min_ending_here = min(arr[i], min_ending_here + arr[i]);
        min_so_far = min(min_so_far, min_ending_here);
    }
    return min_so_far;
}

// Function to find the maximum circular subarray sum
int circularSubarraySum(vector<int>& arr) {
    int max_kadane = kadaneMax(arr);
    int total_sum = accumulate(arr.begin(), arr.end(), 0);
    int min_kadane = kadaneMin(arr);

    // If all elements are negative, max_kadane will be the maximum element
    if (total_sum == min_kadane) {
        return max_kadane;
    }

    return max(max_kadane, total_sum - min_kadane);
}

int main() {
    vector<int> arr1 = {8, -8, 9, -9, 10, -11, 12};
    cout << "Maximum circular subarray sum: " << circularSubarraySum(arr1) << endl; // Output: 22

    vector<int> arr2 = {10, -3, -4, 7, 6, 5, -4, -1};
    cout << "Maximum circular subarray sum: " << circularSubarraySum(arr2) << endl; // Output: 23

    vector<int> arr3 = {-1, 40, -14, 7, 6, 5, -4, -1};
    cout << "Maximum circular subarray sum: " << circularSubarraySum(arr3) << endl; // Output: 52

    return 0;
}