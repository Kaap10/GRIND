class Solution {
public:
    string compressedString(string word) {
        stringstream result;
        int i = 0;
        int n = word.length();

        while (i < n) {
            char ch = word[i];
            int count = 0;
            while (i < n && count < 9 && word[i] == ch) {
                count++;
                i++;
            }
            result << count << ch;
        }
        return result.str();
    }
};