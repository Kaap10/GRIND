#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0, current_sum = 0;
        int min_length = INT_MAX;
        
        while (right < n) {
            current_sum += nums[right];
            while (current_sum >= target) {
                min_length = min(min_length, right - left + 1);
                current_sum -= nums[left];
                left++;
            }
            right++;
        }
        
        return min_length == INT_MAX ? 0 : min_length;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;
    int result = solution.minSubArrayLen(target, nums);
    cout << "Minimum size subarray length: " << result << endl;
    return 0;
}