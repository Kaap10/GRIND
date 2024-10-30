class Solution {
public:
    int findMin(vector<int>& nums) {
      int n= nums.size();
      sort(nums.begin(),nums.end());
      int result =nums[0];
      return result;
    }
};