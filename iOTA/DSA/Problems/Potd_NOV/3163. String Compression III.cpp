class Solution {
public:
    string compressedString(string word) {
        string comp;
        for (int i = 0; i < word.length();) {
            char currentChar = word[i];
            int count = 0;
            while (i < word.length() && word[i] == currentChar && count < 9) {
                count++;
                i++;
            }
            comp += to_string(count) + currentChar;
        }
        return comp;
    }
};