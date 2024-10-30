class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> result;
        int n = nums.size();
        
        for (int i = 0; i <= n - k; ++i) {
            unordered_map<int, int> freq;
            for (int j = i; j < i + k; ++j) {
                freq[nums[j]]++;
            }
            
            priority_queue<pair<int, int>> pq;
            for (auto& [num, count] : freq) {
                pq.push({count, num});
            }
            
            int sum = 0;
            for (int j = 0; j < x && !pq.empty(); ++j) {
                sum += pq.top().first * pq.top().second;
                pq.pop();
            }
            
            result.push_back(sum);
        }
        
        return result;
    }
};