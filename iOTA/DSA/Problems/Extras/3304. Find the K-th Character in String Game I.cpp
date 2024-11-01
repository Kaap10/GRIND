class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";

        while (word.length() < k) {
            string nextWord;
            for (char c : word) {
                nextWord += (c == 'z') ? 'a' : (c + 1);
            }
            word += nextWord;
        }

        return word[k - 1];
    }
};