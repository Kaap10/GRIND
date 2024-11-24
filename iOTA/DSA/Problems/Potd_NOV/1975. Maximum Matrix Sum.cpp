class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long totalSum = 0;
        int negativeCount = 0;
        int minAbsValue = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                totalSum += abs(matrix[i][j]);
                if (matrix[i][j] < 0) {
                    negativeCount++;
                }
                minAbsValue = min(minAbsValue, abs(matrix[i][j]));
            }
        }
        if (negativeCount % 2 == 0) {
            return totalSum;
        } else {

            return totalSum - 2 * minAbsValue;
        }
    }
};