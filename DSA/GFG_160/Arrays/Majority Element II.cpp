class Solution {
  public:   
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& arr) {
        // Your code goes here.
    int n = arr.size();
    if (n == 0) return {};

    sort(arr.begin(), arr.end());

    vector<int> result;
    int count = 1;
    for (int i = 1; i < n; ++i) {
        if (arr[i] == arr[i - 1]) {
            count++;
        } else {
            if (count > n / 3) {
                result.push_back(arr[i - 1]);
            }
            count = 1;
        }
    }

    if (count > n / 3) {
        result.push_back(arr[n - 1]);
    }

    return result;
}
};