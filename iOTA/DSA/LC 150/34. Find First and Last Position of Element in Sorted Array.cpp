class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
           vector<int> result(2, -1); 

        result[0] = findFirstPosition(nums, target);
        result[1] = findLastPosition(nums, target);

        return result;
    }
    int findFirstPosition(const vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int firstPosition = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                firstPosition = mid;
                right = mid - 1; 
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return firstPosition;
    }
     int findLastPosition(const vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int lastPosition = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                lastPosition = mid;
                left = mid + 1; 
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return lastPosition;
    }
};
