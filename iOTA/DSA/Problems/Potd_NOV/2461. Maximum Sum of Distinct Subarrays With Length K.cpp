class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxSum = 0;
        long long currentSum = 0;
        unordered_map<int, int> elementCount;
        
        for (int i = 0; i < nums.size(); ++i) {
          
            currentSum += nums[i];
            elementCount[nums[i]]++;
            
           
            if (i >= k) {
                currentSum -= nums[i - k];
                elementCount[nums[i - k]]--;
                if (elementCount[nums[i - k]] == 0) {
                    elementCount.erase(nums[i - k]);
                }
            }
            
            if (i >= k - 1 && elementCount.size() == k) {
                maxSum = max(maxSum, currentSum);
            }
        }
        
        return maxSum;
    }
};