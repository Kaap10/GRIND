
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0;
        int end = numbers.size() - 1;
        
        while (start <= end) {
            int pair_sum = numbers[start] + numbers[end];
            if (pair_sum < target) {
                start = start + 1;
            }
            else if (pair_sum > target) {
                end = end - 1;
            }
            else {
                return {start + 1, end + 1};
            }
        }
        
        // no pair 
        return {-1, -1};
    }
};