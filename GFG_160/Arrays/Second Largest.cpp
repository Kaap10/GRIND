class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        int first = INT_MIN;
        int second = INT_MIN;
        
        for(int i : arr) {
            if(first < i) {
                first = i;
            }
        }
        
        for(int i : arr) {
            if(first > i && second < i) {
                second = i;
            }
        }
        
        if(second == INT_MIN) {
            return -1;
        }
        
        return second;
    }
};