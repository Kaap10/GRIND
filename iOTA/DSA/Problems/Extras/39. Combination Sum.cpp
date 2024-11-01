class Solution {
public:
    void backtrack(vector<int>& candidates, int target, vector<int>& current_comb, vector<vector<int>>& result, int start) {
        if (target == 0) {
            result.push_back(current_comb);
            return;
        }
        
        for (int i = start; i < candidates.size(); ++i) {
            if (candidates[i] > target) break; 
            current_comb.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], current_comb, result, i);
            current_comb.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result; 
        vector<int> current_comb;   

        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, current_comb, result, 0);
        
        return result;
    }
};
