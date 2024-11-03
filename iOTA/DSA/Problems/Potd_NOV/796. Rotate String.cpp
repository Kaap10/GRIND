class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }
        string concatenated = s + s;
        int len = goal.size();

        for (int i = 0; i <= concatenated.size() - len; ++i) {
            bool found = true;
            for (int j = 0; j < len; ++j) {
                if (concatenated[i + j] != goal[j]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                return true;
            }
        }

        return false;
    }
};