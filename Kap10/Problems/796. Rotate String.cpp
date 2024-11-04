class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;
        string dummy = s + s;

        return dummy.find(goal) != string::npos;
    }
};