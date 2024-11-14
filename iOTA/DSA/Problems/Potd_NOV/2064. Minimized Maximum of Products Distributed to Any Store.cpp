class Solution {
public:
    bool canDistribute(int n, vector<int>& quantities, int maxProducts) {
        int requiredStores = 0;
        for (int quantity : quantities) {
            requiredStores += (quantity + maxProducts - 1) / maxProducts;
        }
        return requiredStores <= n;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1,
            right = *max_element(quantities.begin(), quantities.end());
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canDistribute(n, quantities, mid)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }
};