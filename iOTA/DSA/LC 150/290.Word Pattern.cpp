class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> charToWord;
        unordered_set<string> mappedWords;
        istringstream stream(s);
        string word;
        int i = 0;

        while (stream >> word) {
            if (i == pattern.size() ||
                (charToWord.count(pattern[i]) &&
                 charToWord[pattern[i]] != word) ||
                (!charToWord.count(pattern[i]) && mappedWords.count(word))) {
                return false;
            }
            charToWord[pattern[i]] = word;
            mappedWords.insert(word);
            i++;
        }

        return i == pattern.size();
    }
};