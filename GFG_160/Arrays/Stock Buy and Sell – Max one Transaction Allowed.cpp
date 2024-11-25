class Solution {
  public:
    int maximumProfit(vector<int>& prices) {
        int maxPro = 0;
        int n = prices.size();
        int minPro = INT_MAX;

        for(int i=0; i<n; i++) {
            minPro = min(minPro, prices[i]);
            maxPro = max(maxPro, prices[i]-minPro);
        }

        return maxPro;
    }
};