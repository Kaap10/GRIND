class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        // code here
        // reverse(arr.begin(), arr.end());
        int n = arr.size();
        int start = 0;
        int end = n-1;
        
        while(start <= end) {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
        
    }
};