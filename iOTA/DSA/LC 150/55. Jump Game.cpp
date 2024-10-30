class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxFar = 0;

        for(int i=0; i<nums.size(); i++) {
            if(i > maxFar) {
                return false;
            }

            maxFar = max(maxFar, i+nums[i]);
        }
        return true;
    }
};